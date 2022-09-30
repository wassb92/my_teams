/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** teams
*/

/*****************************************************************
teams_t
    -> User
        -> Private_messages
        -> Teams
            -> Channels
                -> Threads
                    -> Replies
*****************************************************************/

#pragma once
#include <uuid/uuid.h>
#include <stdbool.h>
#include "server.h"
#include "logging_server.h"

static const char *features_input[] = {
    "/help",
    "/login",
    "/logout",
    "/users",
    "/user",
    "/send",
    "/messages",
    "/subscribe",
    "/subscribed",
    "/unsubscribe",
    "/use",
    "/create",
    "/list",
    "/info",
    NULL
};

/* ------------------------------------ */
/*                MACROS                */

#define CHAN_PRINT_THREADS "0"
#define ERR_ALREADY_EXIST "1"
#define ERR_UNAUTHORIZED "2"
#define ERR_UNKNOWN_CHAN "3"
#define ERR_UNKNOWN_TEAM "4"
#define ERR_UNKNOWN_THREAD "5"
#define ERR_UNKNOWN_USER "6"
#define EVT_CHAN_CREAT "7"
#define EVT_LOG_IN "8"
#define EVT_LOG_OUT "9"
#define EVT_PM_RECEIV "10"
#define EVT_TEAM_CREAT "11"
#define EVT_THREAD_CREAT "12"
#define CLI_EVT_CHAN_CREAT "13"
#define EVT_THREAD_REP_RECEIV "14"
#define PRINT_CHAN "15"
#define PRINT_CHAN_CREAT "16"
#define PRINT_REP_CREAT "17"
#define PRINT_SUB "18"
#define PRINT_TEAM "19"
#define PRINT_TEAM_CREAT "20"
#define PRINT_TEAMS "21"
#define PRINT_THREAD "22"
#define PRINT_THREAD_CREAT "23"
#define PRINT_UNSUB "24"
#define PRINT_USER "25"
#define PRINT_USERS "26"
#define PRINT_HELP "27"
#define PM_PRINT_MSGS "28"
#define TEAM_PRINT_CHANS "29"
#define THREAD_PRINT_REP "30"
#define OTHER_ERROR "31"
#define EVT_USER_USE "32"
#define DO_NOTHING "33"

/* ------------------------------------ */
/*               FEATURES               */

bool help(server_t *server, teams_t *teams);
bool login(server_t *server, teams_t *teams);
bool logout(server_t *server, teams_t *teams);
bool users(server_t *server, teams_t *teams);
bool user(server_t *server, teams_t *teams);
bool send_msg(server_t *server, teams_t *teams);
bool messages(server_t *server, teams_t *teams);
bool subscribe(server_t *server, teams_t *teams);
bool subscribed(server_t *server, teams_t *teams);
bool unsubscribe(server_t *server, teams_t *teams);
bool use(server_t *server, teams_t *teams);
bool create(server_t *server, teams_t *teams);
bool list(server_t *server, teams_t *teams);
bool info(server_t *server, teams_t *teams);

/* ------------------------------------ */
/*                CREATE                */

bool create_teams(server_t *server, teams_t *teams);
bool create_channels(server_t *server, teams_t *teams);
bool create_threads(server_t *server, teams_t *teams);
bool create_replies(server_t *server, teams_t *teams);

/* ------------------------------------ */
/*                 LIST                 */

bool list_teams(server_t *server, teams_t *teams);
bool list_channels(server_t *server, teams_t *teams);
bool list_threads(server_t *server, teams_t *teams);
bool list_replies(server_t *server, teams_t *teams);

/* ------------------------------------ */
/*                 INFO                 */

bool info_user(server_t *server, teams_t *teams);
bool info_team(server_t *server, teams_t *teams);
bool info_channel(server_t *server, teams_t *teams);
bool info_thread(server_t *server, teams_t *teams);

/* ------------------------------------ */
/*          Functions pointer           */

static bool (*features[])(server_t *, teams_t *) = {
    &help,
    &login,
    &logout,
    &users,
    &user,
    &send_msg,
    &messages,
    &subscribe,
    &subscribed,
    &unsubscribe,
    &use,
    &create,
    &list,
    &info,
};

static bool (*features_create[])(server_t *, teams_t *) = {
    &create_teams,
    &create_channels,
    &create_threads,
    &create_replies,
};

static bool (*features_list[])(server_t *, teams_t *) = {
    &list_teams,
    &list_channels,
    &list_threads,
    &list_replies,
};

static bool (*features_info[])(server_t *, teams_t *) = {
    &info_user,
    &info_team,
    &info_channel,
    &info_thread,
};
