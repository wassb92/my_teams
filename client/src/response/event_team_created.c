/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** event_team_created
*/

#include "logging_client.h"

int event_team_created(char **array)
{
    return client_event_team_created(array[1], array[2], array[3]);
}
