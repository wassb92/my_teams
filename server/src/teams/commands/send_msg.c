/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** send_msg
*/

#include "teams.h"
#include "lib.h"
#include <string.h>
#include <stdlib.h>

bool list_add_msg_at_front(message_list_t **front_ptr, message_list_t *elem)
{
    message_list_t *cell = malloc(sizeof(message_list_t));

    if (!cell)
        return false;
    memcpy(cell, elem, sizeof(message_list_t));
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
}

user_t *get_user(server_t *server)
{
    for (int i = 1; i < MAX_CONNECTIONS; ++i) {
        if (server->current_user[i] == NULL || i == server->client_socket)
            continue;
        if (strcmp(server->args[1], server->current_user[i]->uuid) == 0) {
            return server->current_user[i];
        }
    }
    return NULL;
}

static void assign_msg(user_t **user, message_list_t *msg, server_t *server)
{
    *user = get_user(server);
    strcpy(msg->uuid, create_uuid());
    strcpy(msg->sender, server->current_user[server->client_socket]->uuid);
    strcpy(msg->receiver, server->current_user[server->client_socket]->uuid);
    strcpy(msg->body, server->args[2]);
    strcpy(msg->timestamp, get_current_time());
}

static bool assign_user_found(char **user_found, server_t *server)
{
    *user_found = write_in_uuid(server, server->args[1],
        my_strcat((char *[]) { EVT_PM_RECEIV,
            server->args[1], server->args[2], NULL }));
}

bool send_msg(server_t *server, teams_t *teams)
{
    message_list_t msg;
    user_t *user;
    char *user_found = NULL;

    if (server->args[1] == NULL || server->args[2] == NULL)
        return true;
    assign_user_found(&user_found, server);
    if (strcmp("User found", user_found) != 0) {
        server->response = my_strcat((char *[]) { ERR_UNKNOWN_USER,
            server->args[1], NULL });
        return true;
    }
    assign_msg(&user, &msg, server);
    list_add_msg_at_front(
        &server->current_user[server->client_socket]->private_msg, &msg);
    list_add_msg_at_front(&user->private_msg, &msg);
    server->response = my_strcat((char *[]) { DO_NOTHING, NULL });
    server_event_private_message_sended(msg.sender, msg.receiver, msg.body);
    return true;
}
