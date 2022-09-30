/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../../include/list.h"

bool list_add_elem_at_front(teams_t *front_ptr, user_t *elem)
{
    teams_t cell = malloc(sizeof(list_t));

    if (!cell)
        return false;
    cell->user = malloc(sizeof(user_t));
    if (!cell->user)
        return false;
    memcpy(cell->user, elem, sizeof(user_t));
    cell->next = *front_ptr;
    *front_ptr = cell;
    return true;
}

bool list_add_elem_at_back(teams_t *front_ptr, user_t *elem)
{
    teams_t tmp = *front_ptr;
    teams_t cell = NULL;

    if (!(*front_ptr))
        return list_add_elem_at_front(front_ptr, elem);
    cell = malloc(sizeof(teams_t));
    cell->next = NULL;
    cell->user = elem;

    while (tmp->next)
        tmp = tmp->next;

    tmp->next = cell;

    return true;
}

bool list_add_elem_at_position(teams_t *front_ptr, user_t *elem,
    unsigned int position)
{
    teams_t pre = *front_ptr;
    teams_t current = *front_ptr;
    teams_t cell = NULL;

    if (position == 0)
        return list_add_elem_at_front(front_ptr, elem);
    cell = malloc(sizeof(teams_t));
    if (position > list_get_size(*front_ptr) || !cell) {
        free(cell);
        return false;
    }
    cell->user = elem;
    cell->next = NULL;
    for (unsigned int i = 0; i < position; ++i) {
        pre = current;
        current = current->next;
    }
    pre->next = cell;
    cell->next = current;
    return true;
}
