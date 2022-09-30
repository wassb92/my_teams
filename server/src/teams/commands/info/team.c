/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** team
*/

#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

bool info_team(server_t *server, teams_t *teams)
{
    team_t *team = server ? server->teams : NULL;

    while (strcmp(team->uuid,
        server->current_user[server->client_socket]->team_used))
        team = team->next;
    server->response = my_strcat((char *[]) { PRINT_TEAM, team->uuid,
        team->name, team->description, NULL });

    return true;
}
