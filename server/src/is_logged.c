/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** is_logged
*/

#include <unistd.h>
#include <string.h>
#include "teams.h"

bool is_logged(server_t *server)
{
    if (!server->is_logged[server->client_socket]) {
        server->response = ERR_UNAUTHORIZED;
        return false;
    }
    return true;
}

bool write_to_all_sockets(server_t *server)
{
    for (int i = 1; i < MAX_CONNECTIONS; ++i) {
        if (server && server->response && server->current_user[i]
            && server->current_user[i]->fd != -1)
            write(server->current_user[i]->fd, server->response,
                strlen(server->response));
    }
}