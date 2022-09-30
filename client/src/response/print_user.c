/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** print_user
*/

#include <stdlib.h>
#include "logging_client.h"

int print_user(char **array)
{
    return client_print_user(array[1], array[2], atoi(array[3]));
}
