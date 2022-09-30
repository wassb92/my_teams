/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** server
*/

#pragma once

#include <netinet/in.h>
#include <stdbool.h>
#include <uuid/uuid.h>
#include "list.h"

typedef struct client_s {
    char message[MAX_NAME_LENGTH + (UUID_STR_LEN * 4) + PADDING_ARRAY];
    char uuid[UUID_STR_LEN];
    char name[MAX_NAME_LENGTH];
    int sockfd;
} client_t;

typedef struct server_s {
    int all_connections[MAX_CONNECTIONS];
    bool is_logged[MAX_CONNECTIONS];
    char **args;
    char *response;
    char *request;
    int client_socket;
    fd_set read_fd_set;
    client_t client;
    team_t *teams;
    user_t *current_user[MAX_CONNECTIONS];
} server_t;

bool server(server_t *server, int *server_fd);
void usage(void);
int create_tcp_server(const int port);
void init_server(server_t *server, int server_fd);
void set_connection(server_t *server, int *new_fd);
void set_connections(server_t *server);
bool exec_command(server_t *server, teams_t *teams);
bool send_response(int client_socket, char *response);
char *write_in_uuid(server_t *server, char *uuid, char *response);
bool is_logged(server_t *server);
void send_response_all(server_t *server);
bool write_to_all_sockets(server_t *server);
