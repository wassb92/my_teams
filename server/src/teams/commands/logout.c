/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** logout
*/

#include <stdlib.h>
#include <string.h>
#include "logging_server.h"
#include "teams.h"
#include "lib.h"

bool logout(server_t *server, teams_t *teams)
{
    for (teams_t tmp = *teams; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->user->uuid, server->client.uuid) == 0)
            tmp->user->is_logged = false;
    server->current_user[server->client_socket]->is_logged = false;
    server->is_logged[server->client_socket] = false;
    server_event_user_logged_out(
        server->current_user[server->client_socket]->uuid);
    server->response = my_strcat((char *[]) { EVT_LOG_OUT,
        server->current_user[server->client_socket]->uuid,
        server->current_user[server->client_socket]->username, NULL });
    free(server->current_user[server->client_socket]);
    server->current_user[server->client_socket] = NULL;
    write_to_all_sockets(server);
    return true;
}
