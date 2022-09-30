/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** team_print_channels
*/

#include "logging_client.h"

int team_print_channels(char **array)
{
    for (int i = 1; array[i] != NULL; i += 3)
        client_team_print_channels(array[i], array[i + 1], array[i + 2]);
    return 0;
}
