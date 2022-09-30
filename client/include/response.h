/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** response
*/

#pragma once

int channel_print_threads(char **array);
int error_already_exist(char **array);
int error_unauthorized(char **array);
int error_unknown_channel(char **array);
int error_unknown_team(char **array);
int error_unknown_thread(char **array);
int error_unknown_user(char **array);
int event_channel_created(char **array);
int event_logged_in(char **array);
int event_logged_out(char **array);
int event_private_message_received(char **array);
int event_team_created(char **array);
int event_thread_created(char **array);
int client_event_channel_created(char **array);
int event_thread_reply_received(char **array);
int print_channel(char **array);
int print_channel_created(char **array);
int print_reply_created(char **array);
int print_subscribed(char **array);
int print_team(char **array);
int print_team_created(char **array);
int print_teams(char **array);
int print_thread(char **array);
int print_thread_created(char **array);
int print_unsubscribed(char **array);
int print_user(char **array);
int print_users(char **array);
int print_help(char **array);
int private_message_print_messages(char **array);
int team_print_channels(char **array);
int thread_print_replies(char **array);
int other_error(char **array);
int event_user_use(char **array);
int do_nothing(char **array);

static int (*responses[])(char **) = {
    &channel_print_threads,
    &error_already_exist,
    &error_unauthorized,
    &error_unknown_channel,
    &error_unknown_team,
    &error_unknown_thread,
    &error_unknown_user,
    &event_channel_created,
    &event_logged_in,
    &event_logged_out,
    &event_private_message_received,
    &event_team_created,
    &event_thread_created,
    &client_event_channel_created,
    &event_thread_reply_received,
    &print_channel,
    &print_channel_created,
    &print_reply_created,
    &print_subscribed,
    &print_team,
    &print_team_created,
    &print_teams,
    &print_thread,
    &print_thread_created,
    &print_unsubscribed,
    &print_user,
    &print_users,
    &print_help,
    &private_message_print_messages,
    &team_print_channels,
    &thread_print_replies,
    &other_error,
    &event_user_use,
    &do_nothing
};
