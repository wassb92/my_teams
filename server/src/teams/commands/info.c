/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** info
*/

#include "teams.h"
#include <string.h>

static bool is_null(char *str)
{
    if (strlen(str) != 0)
        return true;
    return false;
}

bool info(server_t *server, teams_t *teams)
{
    bool te = is_null(server->current_user[server->client_socket]->team_used);
    bool c = is_null(server->current_user[server->client_socket]->chan_used);
    bool t = is_null(server->current_user[server->client_socket]->thread_used);

    if (!te && !c && !t)
        info_user(server, teams);
    if (te && !c && !t)
        info_team(server, teams);
    if (te && c && !t)
        info_channel(server, teams);
    if (te && c && t)
        info_thread(server, teams);

    return true;
}
