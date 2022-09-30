/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** init
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include "const.h"
#include "server.h"

int create_tcp_server(const int port)
{
    struct sockaddr_in addr;
    int fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    int opt = 1;

    if (fd == FAIL)
        return FAIL;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(port);
    addr.sin_addr.s_addr = inet_addr(LOCALHOST);
    if (setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == FAIL)
        return FAIL;
    if (bind(fd, (struct sockaddr *)&addr, sizeof(struct sockaddr_in)) != 0) {
        close(fd);
        return FAIL;
    }
    if (listen(fd, BACKLOG) != 0) {
        close(fd);
        return FAIL;
    }
    return fd;
}

void init_server(server_t *server, int server_fd)
{
    server->args = NULL;
    server->request = NULL;
    server->response = "500 Command Unknown";
    memset(server->is_logged, false, MAX_CONNECTIONS);

    for (size_t i = 0; i < MAX_CONNECTIONS; ++i)
        server->all_connections[i] = FAIL;
    server->all_connections[0] = server_fd;
}

void set_connection(server_t *server, int *new_fd)
{
    for (int i = 0; i < MAX_CONNECTIONS; ++i)
        if (server->all_connections[i] < 0) {
            server->all_connections[i] = *new_fd;
            break;
        }
}

void set_connections(server_t *server)
{
    for (int i = 0; i < MAX_CONNECTIONS; ++i)
        if (server->all_connections[i] >= 0)
            FD_SET(server->all_connections[i], &server->read_fd_set);
}
