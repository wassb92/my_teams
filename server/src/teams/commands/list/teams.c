/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** teams
*/

#include "teams.h"
#include "lib.h"
#include <string.h>

bool list_teams(server_t *server, teams_t *teams)
{
    server->response = strdup(PRINT_TEAMS);
    if (server->teams == NULL)
        return true;
    for (team_t *tmp = server->teams; tmp != NULL; tmp = tmp->next)
        server->response = my_strcat((char *[]) { server->response, tmp->uuid,
            tmp->name, tmp->description, NULL });
    return true;
}
