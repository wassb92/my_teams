/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** print_teams
*/

#include "logging_client.h"

int print_teams(char **array)
{
    for (int i = 1; array[i] != NULL; i += 3)
        client_print_teams(array[i], array[i + 1], array[i + 2]);
    return 0;
}
