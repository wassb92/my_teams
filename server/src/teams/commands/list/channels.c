/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** channels
*/

#include "teams.h"
#include "lib.h"
#include <string.h>

static team_t *get_team(server_t *server, teams_t *teams)
{
    if (server->teams == NULL)
        return NULL;
    for (team_t *tmp = server->teams; tmp != NULL; tmp = tmp->next)
        if (!strcmp(server->current_user[server->client_socket]->team_used,
                tmp->uuid))
            return tmp;
    return NULL;
}

bool list_channels(server_t *server, teams_t *teams)
{
    team_t *team = get_team(server, teams);

    server->response = strdup(TEAM_PRINT_CHANS);
    if (team == NULL)
        return true;
    for (channel_t *tmp = team->channels; tmp != NULL; tmp = tmp->next)
        server->response = my_strcat((char *[]) { server->response, tmp->uuid,
            tmp->name, tmp->description, NULL });
    return true;
}
