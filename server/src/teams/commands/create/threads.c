/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** threads
*/

#include "logging_server.h"
#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

bool list_add_thread_at_front(thread_t **front_ptr, thread_t *elem,
    server_t *server)
{
    thread_t *cell = malloc(sizeof(thread_t));

    if (!cell)
        return false;
    strcpy(elem->uuid, create_uuid());
    strcpy(elem->title, server->args[1]);
    strcpy(elem->message, server->args[2]);
    strcpy(elem->user_uid, server->current_user[server->client_socket]->uuid);
    strcpy(elem->timestamp, get_current_time());
    memcpy(cell, elem, sizeof(thread_t));
    cell->next = *front_ptr;
    *front_ptr = cell;

    return true;
}

channel_t *get_channel(server_t *server, teams_t *teams)
{
    team_t *team = server ? server->teams : NULL;
    channel_t *channel;

    while (strcmp(team->uuid,
        server->current_user[server->client_socket]->team_used))
        team = team->next;
    channel = team ? team->channels : NULL;
    while (strcmp(channel->uuid,
        server->current_user[server->client_socket]->chan_used))
        channel = channel->next;
    return channel;
}

static bool check_arg(server_t *server, teams_t *teams)
{
    int size = 0;

    for (; server->args[size] != NULL; ++size) { }
    if (size != 3) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "Unvalid number of arguments", NULL });
        return false;
    }
    return true;
}

static bool check_already_exists(server_t *server, channel_t *channel)
{
    for (thread_t *thr = channel->threads; thr != NULL; thr = thr->next)
        if (strcmp(thr->title, server->args[1]) == 0) {
            server->response
                = my_strcat((char *[]) { ERR_ALREADY_EXIST, NULL });
            return false;
        }
    return true;
}

bool create_threads(server_t *server, teams_t *teams)
{
    channel_t *channel;
    thread_t thread;

    if (!is_logged(server) || !check_arg(server, teams))
        return false;
    channel = get_channel(server, teams);
    if (!check_already_exists(server, channel))
        return false;
    thread.replies = NULL;
    list_add_thread_at_front(&channel->threads, &thread, server);
    server->response = my_strcat((char *[]) { EVT_THREAD_CREAT, thread.uuid,
        thread.user_uid, thread.timestamp, thread.title, thread.message,
        NULL });
    server_event_thread_created(channel->uuid, thread.uuid,
        thread.user_uid, thread.title, thread.message);
    return true;
}
