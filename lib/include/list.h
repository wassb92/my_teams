/*
** EPITECH PROJECT, 2021
** Paradigms Seminar
** File description:
** Exercise 01
*/

#pragma once

#include <stdbool.h>
#include <uuid/uuid.h>
#include "const.h"

typedef struct message_list_s {
    char uuid[UUID_STR_LEN];
    char receiver[UUID_STR_LEN];
    char sender[UUID_STR_LEN];
    char timestamp[TIMESTAMP_LENGTH];
    char body[MAX_BODY_LENGTH];
    struct message_list_s *next;
} message_list_t;

typedef struct replies_s {
    char user_uid[UUID_STR_LEN];
    char body[MAX_BODY_LENGTH];
    char timestamp[TIMESTAMP_LENGTH];
    struct replies_s *next;
} replies_t;

typedef struct thread_s {
    char uuid[UUID_STR_LEN];
    char title[MAX_NAME_LENGTH];
    char message[MAX_BODY_LENGTH];
    char timestamp[TIMESTAMP_LENGTH];
    char user_uid[UUID_STR_LEN];
    replies_t *replies;
    struct thread_s *next;
} thread_t;

typedef struct channel_s {
    thread_t *threads;
    char uuid[UUID_STR_LEN];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct channel_s *next;
} channel_t;

typedef struct user_team_uuid_s {
    char uuid[UUID_STR_LEN];
    struct user_team_uuid_s *next;
} user_team_uuid_t;

typedef struct team_s {
    user_team_uuid_t *user_uuid;
    channel_t *channels;
    char uuid[UUID_STR_LEN];
    char name[MAX_NAME_LENGTH];
    char description[MAX_DESCRIPTION_LENGTH];
    struct team_s *next;
} team_t;

typedef struct user_s {
    message_list_t *private_msg;
    int fd;
    char team_used[UUID_STR_LEN];
    char chan_used[UUID_STR_LEN];
    char thread_used[UUID_STR_LEN];
    char uuid[UUID_STR_LEN];
    char username[MAX_NAME_LENGTH];
    bool is_logged;
} user_t;

typedef struct list_s {
    user_t *user;
    struct list_s *next;
} list_t;

typedef list_t *teams_t;

unsigned int list_get_size(teams_t list);
bool list_is_empty(teams_t list);

void list_dump(teams_t list);

bool list_add_elem_at_front(teams_t *front_ptr, user_t *elem);
bool list_add_elem_at_back(teams_t *front_ptr, user_t *elem);
bool list_add_elem_at_position(teams_t *front_ptr, user_t *elem,
    unsigned int position);

bool list_del_elem_at_front(teams_t *front_ptr);
bool list_del_elem_at_back(teams_t *front_ptr);
bool list_del_elem_at_position(teams_t *front_ptr, unsigned int position);

void list_clear(teams_t *front_ptr);

user_t *list_get_elem_at_front(teams_t list);
user_t *list_get_elem_at_back(teams_t list);
user_t *list_get_elem_at_position(teams_t list, unsigned int position);
