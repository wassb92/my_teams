/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** users
*/

#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

static bool error_handling(server_t *server, teams_t *teams)
{
    if (!is_logged(server))
        return true;
    return false;
}

bool users(server_t *server, teams_t *teams)
{
    if (error_handling(server, teams)) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "You are not logged in", NULL });
        return true;
    }
    server->response = strdup(PRINT_USERS);
    for (teams_t tmp = *teams; tmp != NULL; tmp = tmp->next) {
        server->response
            = my_strcat((char *[]) { server->response, tmp->user->uuid,
                tmp->user->username, tmp->user->is_logged ? "1" : "0", NULL });
    }
    return true;
}
