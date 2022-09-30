/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** server
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <unistd.h>
#include "teams.h"
#include "server.h"
#include "lib.h"
#include "const.h"

static void close_client(server_t *server, int i, teams_t *teams)
{
    if (is_logged(server))
        logout(server, teams);
    close(server->all_connections[i]);
    server->all_connections[i] = -1;
}

static statement_t manage_connections(int *ret_val, size_t i, server_t *server,
    teams_t *teams)
{
    client_t client = { 0x0, 0x0, 0x0, 0 };

    server->client_socket = server->all_connections[i];
    client.sockfd = server->client_socket;
    *ret_val = read(server->client_socket, &client, sizeof(client));
    if (*ret_val == FAIL)
        return BREAK;
    memcpy(&server->client, &client, sizeof(client));
    server->request = client.message;
    if (!to_array(&server->args, server->request, INPUT_DEL))
        return FALSE;
    if (!exec_command(server, teams))
        return FALSE;
    if (write(server->client_socket, server->response,
            strlen(server->response)) == FAIL)
        return FALSE;
    free_array(server->args);
    free(server->response);
    (*ret_val) == 0 ? close_client(server, i, teams) : 0;
    return TRUE;
}

static bool multiple_connections(server_t *server, int *ret_val,
    teams_t *teams)
{
    statement_t conn = TRUE;

    for (int i = 1; i < MAX_CONNECTIONS; ++i) {
        if (!((server->all_connections[i] > 0)
                && (FD_ISSET(server->all_connections[i],
                    &server->read_fd_set)))) {
            --(*ret_val);
            continue;
        }
        conn = manage_connections(ret_val, i, server, teams);
        if (conn == FALSE)
            return false;
        if (conn == BREAK)
            break;
        --(*ret_val);
    }
    return true;
}

static statement_t accept_client(server_t *server, int *server_fd,
    struct sockaddr_in *new_addr, int *ret_val)
{
    int new_fd = 0;
    socklen_t addrlen = sizeof(*new_addr);

    if (FD_ISSET(*server_fd, &server->read_fd_set)) {
        new_fd = accept(*server_fd, (struct sockaddr *)new_addr, &addrlen);
        if (new_fd < 0)
            return FALSE;
        set_connection(server, &new_fd);
        if (!(--*ret_val))
            return CONTINUE;
    }
    return TRUE;
}

bool server(server_t *server, int *server_fd)
{
    int ret_val = 0;
    struct sockaddr_in new_addr;
    statement_t acpt = TRUE;
    teams_t teams = NULL;

    while (true) {
        FD_ZERO(&server->read_fd_set);
        set_connections(server);
        ret_val = select(FD_SETSIZE, &server->read_fd_set, NULL, NULL, NULL);
        if (ret_val < 0)
            return ERROR;
        acpt = accept_client(server, server_fd, &new_addr, &ret_val);
        if (acpt == CONTINUE)
            continue;
        if (acpt == FALSE)
            return ERROR;
        if (!multiple_connections(server, &ret_val, &teams))
            return ERROR;
    }
}
