/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** help
*/

#include "teams.h"
#include "lib.h"

bool help(server_t *server, teams_t *teams)
{
    char *array[] 
        = {PRINT_HELP, "Available commands:\n\t/help, /login, "
            "/logout, /users, /user\n\t/send, /messages, /subscribe, /subsc"
                "ribed\n\t/unsubscribe, /use, /create, /list, /info", NULL};

    server->response = my_strcat(array);
    return true;
}
