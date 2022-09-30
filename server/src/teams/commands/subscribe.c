/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** subscribe
*/

#include "logging_server.h"
#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

static bool list_add_user_uuid(user_team_uuid_t **front_ptr, char *elem)
{
    user_team_uuid_t *cell = malloc(sizeof(user_team_uuid_t));

    if (!cell)
        return false;
    strcpy(cell->uuid, elem);
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
}

bool subscribe(server_t *server, teams_t *teams)
{
    team_t *team = NULL;

    if (server->args[1] == NULL)
        return true;
    for (team = server->teams; team != NULL; team = team->next)
        if (strcmp(team->uuid, server->args[1]) == 0) {
            list_add_user_uuid(&team->user_uuid,
                server->current_user[server->client_socket]->uuid);
            server->response = my_strcat((char *[]) { PRINT_SUB,
                server->current_user[server->client_socket]->uuid,
                team->uuid, NULL });
            server_event_user_subscribed(team->uuid,
                server->current_user[server->client_socket]->uuid);
            return true;
        }
    server->response = my_strcat((char *[]) { ERR_UNKNOWN_TEAM,
        server->args[1], NULL });
    return true;
}
