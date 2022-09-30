/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** messages
*/

#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

char *check_user_uuid(server_t *server)
{
    for (int i = 1; i < MAX_CONNECTIONS; ++i) {
        if (server->current_user[i] == NULL || i == server->client_socket)
            continue;
        if (strcmp(server->args[1], server->current_user[i]->uuid) == 0) {
            return "User found";
        }
    }
    return NULL;
}

bool messages(server_t *server, teams_t *teams)
{
    char *check_user = check_user_uuid(server);

    if (check_user == NULL) {
        server->response = my_strcat((char *[]) { ERR_UNKNOWN_USER,
            server->args[1], NULL });
        return true;
    }
    server->response = strdup(PM_PRINT_MSGS);
    for (message_list_t *msg
         = server->current_user[server->client_socket]->private_msg;
         msg; msg = msg->next) {
        if (strcmp(msg->receiver, server->args[1]) == 0) {
            server->response
                = my_strcat((char *[]) { server->response, msg->sender,
                    msg->timestamp, msg->body, NULL });
        }
    }
    return true;
}
