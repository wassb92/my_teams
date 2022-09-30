/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** event_logged_in
*/

#include "logging_client.h"

int event_logged_in(char **array)
{
    return client_event_logged_in(array[1], array[2]);
}
