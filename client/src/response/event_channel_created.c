/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** event_channel_created
*/

#include "logging_client.h"

int event_channel_created(char **array)
{
    return client_event_channel_created(array[1], array[2], array[3]);
}
