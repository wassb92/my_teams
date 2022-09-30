/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** channels
*/

#include "teams.h"
#include "lib.h"
#include "logging_server.h"
#include <string.h>
#include <stdlib.h>

bool list_add_channel_at_front(channel_t **front_ptr, channel_t *elem)
{
    channel_t *cell = malloc(sizeof(channel_t));

    if (!cell)
        return false;
    memcpy(cell, elem, sizeof(channel_t));
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
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

static bool check_already_exists(server_t *server, team_t *team)
{
    for (channel_t *chan = team->channels; chan != NULL; chan = chan->next)
        if (strcmp(chan->name, server->args[1]) == 0) {
            server->response
                = my_strcat((char *[]) { ERR_ALREADY_EXIST, NULL });
            return false;
        }
    return true;
}

bool create_channels(server_t *server, teams_t *teams)
{
    team_t *team = server ? server->teams : NULL;
    channel_t channel;

    if (!is_logged(server) || !check_arg(server, teams))
        return true;
    while (strcmp(team->uuid,
        server->current_user[server->client_socket]->team_used))
        team = team->next;
    if (!check_already_exists(server, team))
        return false;
    channel.threads = NULL;
    strcpy(channel.uuid, create_uuid());
    strcpy(channel.name, server->args[1]);
    strcpy(channel.description, server->args[2]);
    list_add_channel_at_front(&team->channels, &channel);
    server_event_channel_created(team->uuid, channel.uuid, channel.name);
    server->response = my_strcat((char *[]) { EVT_CHAN_CREAT, channel.uuid,
        channel.name, channel.description, NULL });
    return true;
}
