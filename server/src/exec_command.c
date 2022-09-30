/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** exec_commands
*/

#include <string.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include "server.h"
#include "teams.h"
#include "lib.h"

void send_response_all(server_t *server)
{
    int len = strlen(server->response);

    for (int i = 1; i < MAX_CONNECTIONS; ++i) {
        if (server->all_connections[i] == FAIL
            || server->current_user[i] == NULL || i == server->client_socket)
            continue;
        write(server->all_connections[i], server->response, len);
    }
}

char *write_in_uuid(server_t *server, char *uuid, char *response)
{
    for (int i = 1; i < MAX_CONNECTIONS; ++i) {
        if (i == server->client_socket || server->current_user[i] == NULL)
            continue;
        if (strcmp(uuid, server->current_user[i]->uuid) == 0) {
            write(server->current_user[i]->fd, response, strlen(response));
            return "User found";
        }
    }
    return ERR_UNKNOWN_USER;
}

static void find_user(server_t *server, teams_t *teams)
{
    for (teams_t tmp = *teams; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->user->uuid, server->client.uuid) == 0) {
            server->current_user[server->client_socket]
                = malloc(sizeof(user_t));
            memcpy(server->current_user[server->client_socket], tmp->user,
                sizeof(user_t));
            return;
        }
}

static bool leave_client(server_t *server, teams_t *teams)
{
    if (is_logged(server))
        logout(server, teams);
    else
        server->response = strdup(OTHER_ERROR);
    return true;
}

bool exec_command(server_t *server, teams_t *teams)
{
    if (server->args[0] == NULL)
        return leave_client(server, teams);
    if (is_logged(server))
        find_user(server, teams);
    server->response = my_strcat((char *[]) { OTHER_ERROR,
        "Unknown Command", NULL });
    if (!is_logged(server) && strcmp(server->args[0], "/login") != 0) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "You are not logged in", NULL });
        return true;
    }
    for (size_t i = 0; features_input[i] != NULL; ++i)
        if (strcmp(server->args[0], features_input[i]) == 0)
            return (features)[i](server, teams);
    return TRUE;
}
