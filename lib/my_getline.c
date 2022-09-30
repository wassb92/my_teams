/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** my_getline
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>
#include "const.h"
#include "lib.h"

char *my_getline(void)
{
    char *input = NULL;
    char *str = NULL;
    size_t size = 0;

    if (getline(&input, &size, stdin) == -1) {
        free(input);
        return NULL;
    }
    if (size == 0)
        return NULL;
    if (input[strlen(input) - 1] == '\n')
        input[strlen(input) - 1] = '\0';
    str = clean_str(input);
    free(input);
    return str;
}
