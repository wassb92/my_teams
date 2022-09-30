/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** event_private_message_received
*/

#include "logging_client.h"

int event_private_message_received(char **array)
{
    return client_event_private_message_received(array[1], array[2]);
}
