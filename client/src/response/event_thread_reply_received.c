/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** event_thread_reply_received
*/

#include "logging_client.h"

int event_thread_reply_received(char **array)
{
    return client_event_thread_reply_received(array[1], array[2],
        array[3], array[4]);
}
