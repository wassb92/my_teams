/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** teams
*/

#include "teams.h"
#include "lib.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>

bool list_add_team_at_front(team_t **front_ptr, team_t *elem)
{
    team_t *cell = malloc(sizeof(team_t));

    if (!cell)
        return false;
    memcpy(cell, elem, sizeof(team_t));
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
}

static bool check_arg(server_t *server, teams_t *teams)
{
    int size = 0;

    for (team_t *team = server->teams; team; team = team->next)
        if (strcmp(team->name, server->args[1]) == 0) {
            server->response
                = my_strcat((char *[]) { ERR_ALREADY_EXIST, NULL });
            return false;
        }
    for (; server->args[size] != NULL; ++size) { }
    if (size != 3) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "Unvalid number of arguments", NULL });
        return false;
    }
    return true;
}

bool create_teams(server_t *server, teams_t *teams)
{
    team_t *team = NULL;

    if (!is_logged(server) || !check_arg(server, teams))
        return true;
    team = malloc(sizeof(team_t));
    team->user_uuid = NULL;
    team->channels = NULL;
    strcpy(team->uuid, create_uuid());
    strcpy(team->name, server->args[1]);
    strcpy(team->description, server->args[2]);
    list_add_team_at_front(&server->teams, team);
    server_event_team_created(team->uuid, team->name,
        server->current_user[server->client_socket]->uuid);
    server->response = my_strcat((char *[]) { PRINT_TEAM_CREAT, team->uuid,
        team->name, team->description, NULL });
    send_response_all(server);
    server->response = my_strcat((char *[]) { EVT_TEAM_CREAT, team->uuid,
        team->name, team->description, NULL });
    return true;
}
