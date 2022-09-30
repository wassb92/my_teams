/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** thread_print_replies
*/

#include "logging_client.h"
#include "lib.h"

int thread_print_replies(char **array)
{
    for (int i = 1; array[i] != NULL; i += 4)
        client_thread_print_replies(array[i], array[i + 1],
            str_to_time(array[3]), array[i + 3]);
    return 0;
}
