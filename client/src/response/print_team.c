/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** print_team
*/

#include "logging_client.h"

int print_team(char **array)
{
    return client_print_team(array[1], array[2], array[3]);
}
