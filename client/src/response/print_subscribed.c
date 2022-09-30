/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** print_subscribed
*/

#include "logging_client.h"

int print_subscribed(char **array)
{
    for (int i = 1; array[i] != NULL; i += 2)
        client_print_subscribed(array[i], array[i + 1]);
    return 0;
}
