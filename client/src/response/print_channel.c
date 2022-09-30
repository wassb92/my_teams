/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** print_channel
*/

#include "logging_client.h"

int print_channel(char **array)
{
    return client_print_channel(array[1], array[2], array[3]);
}
