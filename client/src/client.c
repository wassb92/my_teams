/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** client
*/

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <sys/select.h>
#include <sys/time.h>
#include "lib.h"
#include "const.h"
#include "client.h"
#include "logging_client.h"

static bool create_user(client_t *client)
{
    if (strlen(client->message) <= 6) {
        return false;
    }
    strcpy(client->uuid, create_uuid());
    return true;
}

static statement_t manage_client(client_t *client, int sockfd)
{
    char response[DATA_BUFFER];
    char *request = my_getline();

    if (!request)
        return FALSE;
    strcpy(client->message, (strlen(request) == 0 ? " " : request));
    free(request);
    if (strncmp(client->message, "/login", 6) == 0
        && !create_user(client))
        return CONTINUE;
    if (write(sockfd, client, sizeof(*client)) == -1)
        return FALSE;
    memset(response, 0, DATA_BUFFER);
    if (read(sockfd, response, DATA_BUFFER) == -1)
        return FALSE;
    call_response(response);
    return TRUE;
}

void async_response(client_t *client, int sockfd)
{
    memset(client->message, 0, sizeof(client->message));
    if (read(sockfd, client->message, DATA_BUFFER) > 0)
        call_response(client->message);
}

static bool loop_client(client_t *client, int sockfd)
{
    struct sockaddr_in server;
    fd_set readfds;
    statement_t ret_val = TRUE;

    while (true) {
        FD_ZERO(&readfds);
        FD_SET(STDIN_FILENO, &readfds);
        FD_SET(sockfd, &readfds);
        if (select(sockfd + 1, &readfds, NULL, NULL, NULL) == -1)
            return false;
        if (FD_ISSET(STDIN_FILENO, &readfds))
            ret_val = manage_client(client, sockfd);
        else if (ret_val != FALSE && FD_ISSET(sockfd, &readfds))
            async_response(client, sockfd);
        if (ret_val == FALSE)
            return false;
    }
    return true;
}

bool client(const char *ip, const int port)
{
    int sockfd = socket(AF_INET, SOCK_STREAM, 0);
    client_t client;

    memset(&client, 0x0, sizeof(client));
    if (sockfd == -1) {
        printf("Could not create socket\n");
        return false;
    }
    if (!init_socket(ip, port, sockfd))
        return false;
    if (!loop_client(&client, sockfd))
        return false;
    close(sockfd);
    return true;
}
