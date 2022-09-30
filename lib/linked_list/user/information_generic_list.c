/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/list.h"

unsigned int list_get_size(teams_t list)
{
    unsigned int i = 0;

    for (; list; ++i, list = list->next) { }

    return i;
}

bool list_is_empty(teams_t list)
{
    return (list == NULL);
}

void list_dump(teams_t list)
{
    printf("hello world\n");
}
