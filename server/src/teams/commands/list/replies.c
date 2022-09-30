/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** replies
*/

#include "teams.h"
#include "lib.h"
#include <string.h>

static thread_t *get_thread(server_t *server, channel_t *chan)
{
    if (chan == NULL)
        return NULL;
    for (thread_t *tmp = chan->threads; tmp != NULL; tmp = tmp->next)
        if (!strcmp(server->current_user[server->client_socket]->thread_used,
                tmp->uuid))
            return tmp;
    return NULL;
}

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

bool list_replies(server_t *server, teams_t *teams)
{
    thread_t *thread;

    thread = get_thread(server, get_channel(server, get_team(server, teams)));
    server->response = strdup(THREAD_PRINT_REP);
    if (thread == NULL)
        return true;
    for (replies_t *tmp = thread->replies; tmp != NULL; tmp = tmp->next)
        server->response = my_strcat((char *[]) { server->response,
            thread->uuid, tmp->user_uid, tmp->timestamp, tmp->body, NULL });
    return true;
}
