/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** list
*/

#include "teams.h"
#include <string.h>

bool list(server_t *server, teams_t *teams)
{
    if (strlen(server->current_user[server->client_socket]->team_used) == 0)
        return list_teams(server, teams);
    if (strlen(server->current_user[server->client_socket]->chan_used) == 0)
        return list_channels(server, teams);
    if (strlen(server->current_user[server->client_socket]->thread_used) == 0)
        return list_threads(server, teams);
    return list_replies(server, teams);
}
