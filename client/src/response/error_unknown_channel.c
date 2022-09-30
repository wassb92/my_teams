/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** error_unknown_channel
*/

#include "logging_client.h"

int error_unknown_channel(char **array)
{
    return client_error_unknown_channel(array[1]);
}
