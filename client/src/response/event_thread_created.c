/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** event_thread_created
*/

#include "lib.h"
#include "logging_client.h"

int event_thread_created(char **array)
{
    return client_event_thread_created(array[1], array[2],
        str_to_time(array[3]), array[4], array[5]);
}
