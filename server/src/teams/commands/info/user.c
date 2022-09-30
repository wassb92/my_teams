/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** user
*/

#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

bool info_user(server_t *server, teams_t *teams)
{
    server->response = my_strcat((char *[]) { PRINT_USER,
        server->current_user[server->client_socket]->uuid,
        server->current_user[server->client_socket]->username,
        server->current_user[server->client_socket]->is_logged ? "1" : "0",
        NULL });

    return true;
}
