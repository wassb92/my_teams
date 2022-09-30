/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** channel
*/

#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

bool info_channel(server_t *server, teams_t *teams)
{
    team_t *team = server ? server->teams : NULL;
    channel_t *chan = team ? team->channels : NULL;

    while (strcmp(team->uuid,
        server->current_user[server->client_socket]->team_used))
        team = team->next;
    while (strcmp(chan->uuid,
        server->current_user[server->client_socket]->chan_used))
        chan = chan->next;
    server->response = my_strcat((char *[]) { PRINT_CHAN, chan->uuid,
        chan->name, chan->description, NULL });

    return true;
}
