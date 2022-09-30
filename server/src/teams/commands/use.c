/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** use
*/

#include "teams.h"
#include "lib.h"
#include <string.h>

static bool find_thread(server_t *server, channel_t *chan)
{
    if (server->args[3] == NULL)
        return true;
    for (thread_t *tmp = chan->threads; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->uuid, server->args[3]) == 0) {
            strcpy(server->current_user[server->client_socket]->thread_used,
                tmp->uuid);
            return true;
        }
    server->response = my_strcat((char *[]) { ERR_UNKNOWN_THREAD,
        server->args[3], NULL });
    return false;
}

static bool find_channel(server_t *server, team_t *team)
{
    if (server->args[2] == NULL)
        return true;
    for (channel_t *tmp = team->channels; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->uuid, server->args[2]) == 0) {
            strcpy(server->current_user[server->client_socket]->chan_used,
                tmp->uuid);
            return find_thread(server, tmp);
        }
    server->response = my_strcat((char *[]) { ERR_UNKNOWN_CHAN,
        server->args[2], NULL });
    return false;
}

static bool find_team(server_t *server)
{
    if (server->args[1] == NULL) {
        memset(&server->current_user[server->client_socket]->team_used, 0,
            sizeof(server->current_user[server->client_socket]->team_used));
        memset(&server->current_user[server->client_socket]->chan_used, 0,
            sizeof(server->current_user[server->client_socket]->chan_used));
        memset(&server->current_user[server->client_socket]->thread_used, 0,
            sizeof(server->current_user[server->client_socket]->thread_used));
        return true;
    }
    for (team_t *tmp = server->teams; tmp != NULL; tmp = tmp->next)
        if (strcmp(tmp->uuid, server->args[1]) == 0) {
            strcpy(server->current_user[server->client_socket]->team_used,
                tmp->uuid);
            return find_channel(server, tmp);
        }
    server->response = my_strcat((char *[]) { ERR_UNKNOWN_TEAM,
        server->args[1], NULL });
    return false;
}

bool use(server_t *server, teams_t *teams)
{
    if (!is_logged(server))
        return true;
    if (!find_team(server))
        return true;
    server->response = my_strcat((char *[]) { EVT_USER_USE,
        "Successfully used", NULL });
    return true;
}
