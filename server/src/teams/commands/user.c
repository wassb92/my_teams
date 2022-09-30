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

bool user(server_t *server, teams_t *teams)
{
    teams_t users;

    if (server->args[1] == NULL) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "Unvalid number of arguments", NULL });
        return true;
    }
    for (users = *teams; users; users = users->next) {
        if (strcmp(users->user->uuid, server->args[1]) == 0) {
            server->response = my_strcat((char *[]) { PRINT_USER,
                users->user->uuid, users->user->username,
                users->user->is_logged ? "1" : "0", NULL });
            return true;
        }
    }
    server->response = my_strcat((char *[]) { OTHER_ERROR,
        "Unvalid user", NULL });
    return true;
}