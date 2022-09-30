/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** print_thread_created
*/

#include "logging_client.h"
#include "lib.h"

int print_thread_created(char **array)
{
    return client_print_thread_created(array[1], array[2],
        str_to_time(array[3]), array[4], array[5]);
}
