/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** replies
*/

#include "logging_server.h"
#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

bool list_add_replies_at_front(replies_t **front_ptr, replies_t *elem)
{
    replies_t *cell = malloc(sizeof(replies_t));

    if (!cell)
        return false;
    memcpy(cell, elem, sizeof(replies_t));
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
}

static bool check_arg(server_t *server, teams_t *teams)
{
    int size = 0;

    for (; server->args[size] != NULL; ++size) { }
    if (size != 2) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "Unvalid number of arguments", NULL });
        return false;
    }
    return true;
}

thread_t *get_thread(server_t *server, teams_t *teams)
{
    team_t *team = server ? server->teams : NULL;
    channel_t *channel;
    thread_t *thread;

    while (strcmp(team->uuid,
        server->current_user[server->client_socket]->team_used))
        team = team->next;
    channel = team ? team->channels : NULL;
    while (strcmp(channel->uuid,
        server->current_user[server->client_socket]->chan_used))
        channel = channel->next;
    thread = channel ? channel->threads : NULL;
    while (strcmp(thread->uuid,
        server->current_user[server->client_socket]->thread_used))
        thread = thread->next;
    return thread;
}

bool create_replies(server_t *server, teams_t *teams)
{
    thread_t *thread;
    replies_t reply;

    if (!is_logged(server) || !check_arg(server, teams))
        return true;
    thread = get_thread(server, teams);
    strcpy(reply.body, server->args[1]);
    strcpy(reply.user_uid, server->current_user[server->client_socket]->uuid);
    strcpy(reply.timestamp, get_current_time());
    list_add_replies_at_front(&thread->replies, &reply);
    server->response = my_strcat((char *[]) { PRINT_REP_CREAT, thread->uuid,
        reply.user_uid, reply.timestamp, reply.body, NULL });
    server_event_reply_created(thread->uuid, thread->user_uid, reply.body);
    return true;
}
