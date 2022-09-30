/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** clean_str
*/

#include <stdlib.h>
#include <string.h>

char *clean_str(char *str)
{
    char *new_str = malloc(sizeof(char) * (strlen(str) + 1));
    int i = 0;
    size_t t = 0;

    if (!new_str)
        return NULL;
    for (; str[t] == ' ' || str[t] == '\t'; ++t) { }
    for (; str[t] != '\0'; ++t) {
        if ((str[t] == ' ' || str[t] == '\t')
            && (str[t + 1] == ' ' || str[t + 1] == '\t'))
            continue;
        new_str[i] = str[t];
        ++i;
    }
    if (new_str[i - 1] == ' ' || new_str[i - 1] == '\t')
        new_str[i - 1] = '\0';
    else
        new_str[i] = '\0';

    return new_str;
}
