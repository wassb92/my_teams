/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** private_message_print_messages
*/

#include "logging_client.h"
#include "lib.h"

int private_message_print_messages(char **array)
{
    for (int i = 1; array[i] != NULL; i += 3)
        client_private_message_print_messages(array[i],
            str_to_time(array[i + 1]), array[i + 2]);
    return 0;
}
