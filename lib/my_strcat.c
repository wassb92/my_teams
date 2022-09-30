/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** my_strcat
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "const.h"
#include "lib.h"

static size_t all_char(char **array)
{
    size_t count = 0;

    for (size_t i = 0; array[i] != NULL; ++i)
        count += strlen(array[i]);

    return count;
}

static void fill_str(char **str, char *src, int *i, size_t array_len)
{
    static int count = 0;

    if (src != NULL)
        for (int t = 0; src[t] != '\0'; ++t, ++*i)
            (*str)[*i] = src[t];
    ++count;
    if (count < array_len && strlen(src) > 0) {
        (*str)[*i] = *RESPONSE_DEL;
        ++*i;
    }
    if (count == array_len) {
        count = 0;
        (*str)[*i] = '\0';
    }
}

char *my_strcat(char **array)
{
    unsigned int i = 0;
    size_t len = 0;
    char *str = malloc(tablen(array) + all_char(array));

    if (!str)
        return NULL;
    for (int t = 0; t < tablen(array); ++t)
        fill_str(&str, array[t], &i, tablen(array));
    return str;
}
