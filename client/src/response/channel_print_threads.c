/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** channel_print_threads
*/

#include "lib.h"
#include "logging_client.h"

int channel_print_threads(char **array)
{
    for (int i = 1; array[i] != NULL; i += 5)
        client_channel_print_threads(array[i], array[i + 1],
            str_to_time(array[3]), array[i + 3], array[i + 4]);
    "Thu Jan  1 00:59:59 1970";
    return 0;
}
