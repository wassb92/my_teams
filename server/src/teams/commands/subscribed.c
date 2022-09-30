/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** subscribed
*/

#include "teams.h"
#include "lib.h"
#include <string.h>

static void get_subed_teams(server_t *server, team_t *team)
{
    if (team->user_uuid == NULL)
        return;
    for (user_team_uuid_t *tmp = team->user_uuid; tmp != NULL; tmp = tmp->next)
        if (!strcmp(server->current_user[server->client_socket]->uuid,
                tmp->uuid)) {
            server->response = my_strcat((char *[]) { server->response,
                team->uuid, team->name, team->description, NULL });
            return;
        }
}

static team_t *get_all_subed_teams(server_t *server)
{
    for (team_t *tmp = server->teams; tmp != NULL; tmp = tmp->next)
        get_subed_teams(server, tmp);
}

static void get_subed_user(server_t *server, teams_t *teams,
    user_team_uuid_t *list)
{
    for (teams_t user = *teams; user != NULL; user = user->next)
        if (strcmp(list->uuid, user->user->uuid) == 0)
            server->response = my_strcat((char *[]) { server->response,
                user->user->uuid, user->user->username,
                user->user->is_logged ? "1" : "0", NULL });
}

static bool get_user_list(server_t *server, teams_t *teams)
{
    team_t *team = NULL;

    if (server->teams == NULL)
        return NULL;
    for (team_t *tmp = server->teams; tmp != NULL; tmp = tmp->next)
        if (strcmp(server->args[1], tmp->uuid) == 0)
            team = tmp;
    if (team == NULL) {
        server->response = my_strcat((char *[]) { ERR_UNKNOWN_TEAM,
            server->args[1], NULL });
        return false;
    }
    for (user_team_uuid_t *ids = team->user_uuid; ids != NULL; ids = ids->next)
        get_subed_user(server, teams, ids);
    return true;
}

bool subscribed(server_t *server, teams_t *teams)
{
    if (server->teams == NULL)
        return true;
    if (server->args[1] == NULL) {
        server->response = strdup(PRINT_TEAMS);
        if (server->teams == NULL)
            return true;
        get_all_subed_teams(server);
    } else if (server->args[2] == NULL) {
        server->response = strdup(PRINT_USERS);
        get_user_list(server, teams);
    }
    return true;
}
