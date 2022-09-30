/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** call_from_response
*/

#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"
#include "const.h"
#include "response.h"

bool call_response(char *response)
{
    char **array = NULL;

    if (!to_array(&array, response, RESPONSE_DEL))
        return false;
    responses[atoi(array[0])](array);
    free_array(array);
    return true;
}
