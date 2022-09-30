/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** lib
*/

#include "const.h"
#include <stdbool.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include <stdio.h>

bool is_double_quoted(char *str, char *full_request)
{
    char *found = NULL;
    int pos = 0;

    if (strlen(full_request) > 0) {
        found = strstr(full_request, str);
        if (found != NULL)
            pos = (int)(found - full_request);
    }
    return (full_request[pos - 1] == '\"'
        && full_request[pos + strlen(str)] == '\"');
}

time_t str_to_time(char *str)
{
    struct tm time;

    memset(&time, 0, sizeof(time));
    strptime(str, "%Y-%m-%d %H:%M:%S", &time);
    return mktime(&time);
}

char *get_current_time(void)
{
    static char buff[20];
    time_t now = time(NULL);

    strftime(buff, 20, "%Y-%m-%d %H:%M:%S", localtime(&now));

    time_t tmp = str_to_time(buff);
    return buff;
}

size_t tablen(char **array)
{
    size_t i = 0;

    for (; array[i] != NULL; ++i) { }

    return i;
}
