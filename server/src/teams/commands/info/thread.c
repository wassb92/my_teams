/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** thread
*/

#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

bool info_thread(server_t *server, teams_t *teams)
{
    team_t *team = server ? server->teams : NULL;
    channel_t *chan = team ? team->channels : NULL;
    thread_t *thr = chan ? chan->threads : NULL;

    while (strcmp(team->uuid,
        server->current_user[server->client_socket]->team_used))
        team = team->next;
    while (strcmp(chan->uuid,
        server->current_user[server->client_socket]->chan_used))
        chan = chan->next;
    while (strcmp(thr->uuid,
        server->current_user[server->client_socket]->thread_used))
        thr = thr->next;
    server->response = my_strcat((char *[]) { PRINT_THREAD,
        thr->uuid, thr->user_uid, thr->timestamp, thr->title, thr->message,
        NULL });

    return true;
}