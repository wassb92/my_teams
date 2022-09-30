/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** threads
*/

#include "teams.h"
#include "lib.h"
#include <string.h>

static channel_t *get_channel(server_t *server, team_t *team)
{
    if (team == NULL)
        return NULL;
    for (channel_t *tmp = team->channels; tmp != NULL; tmp = tmp->next)
        if (!strcmp(server->current_user[server->client_socket]->chan_used,
                tmp->uuid))
            return tmp;
    return NULL;
}

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

bool list_threads(server_t *server, teams_t *teams)
{
    channel_t *chan = get_channel(server, get_team(server, teams));

    server->response = strdup(CHAN_PRINT_THREADS);
    if (chan == NULL)
        return true;
    for (thread_t *tmp = chan->threads; tmp != NULL; tmp = tmp->next)
        server->response = my_strcat((char *[]) { server->response, tmp->uuid,
            tmp->user_uid, tmp->timestamp, tmp->title, tmp->message, NULL });
    return true;
}
