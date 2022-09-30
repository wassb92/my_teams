/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** login
*/

#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include "teams.h"
#include "logging_server.h"
#include "lib.h"

static bool error_handling(server_t *server, teams_t *teams)
{
    if (server->args[1] == NULL) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "Missing argument", NULL });
        return true;
    }
    if (server->is_logged[server->client_socket]) {
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "User already logged", NULL });
        return true;
    }
    if (!is_double_quoted(server->args[1], server->request))
        server->response = my_strcat((char *[]) { OTHER_ERROR,
            "Bad arguments (need double quote)", NULL });
    return false;
}

static bool check_user_exists(server_t *server, teams_t *teams, user_t *user)
{
    for (teams_t team = *teams; team != NULL; team = team->next)
        if (strcmp(team->user->username, user->username) == 0) {
            server_event_user_logged_in(team->user->uuid);
            team->user->is_logged = true;
            memcpy(user, team->user, sizeof(user_t));
            server->response = my_strcat((char *[]) { EVT_LOG_IN,
                team->user->uuid, team->user->username, NULL });
            return true;
        }
    if (!list_add_elem_at_front(teams, user))
        return false;
    server_event_user_created(user->uuid, user->username);
    server_event_user_logged_in(user->uuid);
    server->response = my_strcat((char *[]) { EVT_LOG_IN, user->uuid,
        user->username, NULL });
    write_to_all_sockets(server);
    return false;
}

static void set_new_user(server_t *server, user_t *user)
{
    user->private_msg = malloc(sizeof(message_list_t));
    memset(user->private_msg, 0, sizeof(message_list_t));
    memset(user->team_used, 0, sizeof(user->team_used));
    memset(user->chan_used, 0, sizeof(user->chan_used));
    memset(user->thread_used, 0, sizeof(user->thread_used));
    strcpy(user->uuid, server->client.uuid);
    strcpy(user->username, server->args[1]);
    user->fd = server->client_socket;
}

bool login(server_t *server, teams_t *teams)
{
    user_t elem;

    if (error_handling(server, teams))
        return true;
    elem.is_logged = true;
    server->is_logged[server->client_socket] = true;
    set_new_user(server, &elem);
    if (!check_user_exists(server, teams, &elem)
        || !server->current_user[server->client_socket])
        server->current_user[server->client_socket] = malloc(sizeof(user_t));
    memcpy(server->current_user[server->client_socket], &elem, sizeof(user_t));
    if (server->response == NULL)
        return false;
    return true;
}
