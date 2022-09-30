/*
** EPITECH PROJECT, 2022
** myteams
** File description:
** client
*/

#pragma once

#include <stdbool.h>
#include <uuid/uuid.h>
#include "const.h"

typedef struct client_s {
    char message[MAX_NAME_LENGTH + (UUID_STR_LEN * 4) + PADDING_ARRAY];
    char uuid[UUID_STR_LEN];
    char name[MAX_NAME_LENGTH];
} client_t;

void usage(void);
bool client(const char *ip, const int port);
void call_response(char *response);
bool init_socket(const char *ip, const int port, int sockfd);
