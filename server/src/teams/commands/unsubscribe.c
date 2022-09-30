/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** unsubscribe
*/

#include "teams.h"
#include "lib.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>

static bool list_del_user_at_front(user_team_uuid_t *front_ptr)
{
    user_team_uuid_t *tmp = front_ptr;

    if (!tmp)
        return false;
    front_ptr = front_ptr->next;
    free(tmp);
    return true;
}

static bool check_others(server_t *server, team_t *team)
{
    user_team_uuid_t *tmp = NULL;

    for (; team->user_uuid != NULL; team->user_uuid = team->user_uuid->next) {
        if (!strcmp(team->user_uuid->next->uuid,
                server->current_user[server->client_socket]->uuid)) {
            tmp = team->user_uuid->next;
            team->user_uuid->next = team->user_uuid->next->next;
            free(tmp);
            server->response = my_strcat((char *[]) { PRINT_UNSUB,
                server->current_user[server->client_socket]->uuid,
                team->uuid, NULL });
            server_event_user_unsubscribed(team->uuid,
                server->current_user[server->client_socket]->uuid);
            return false;
        }
    }
    return true;
}

static bool check_first(server_t *server, team_t *team)
{
    if (!strcmp(team->user_uuid->uuid,
            server->current_user[server->client_socket]->uuid)) {
        list_del_user_at_front(team->user_uuid);
        server->response = my_strcat((char *[]) { PRINT_UNSUB,
            server->current_user[server->client_socket]->uuid,
            team->uuid, NULL });
        server_event_user_unsubscribed(team->uuid,
            server->current_user[server->client_socket]->uuid);
        return false;
    }
    return check_others(server, team);
}

bool unsubscribe(server_t *server, teams_t *teams)
{
    team_t *tm = NULL;
    user_team_uuid_t *user = NULL;

    for (tm = server->teams;
         strcmp(server->teams->uuid, server->args[1]) != 0; tm = tm->next) {
        if (tm == NULL) {
            server->response = my_strcat((char *[]) { OTHER_ERROR,
                "Team doesnt exist", NULL });
            return true;
        }
    }
    if (!check_first(server, tm))
        return true;
    server->response = my_strcat((char *[]) { OTHER_ERROR,
        "User is not subscribed to the team", NULL });
    return true;
}
