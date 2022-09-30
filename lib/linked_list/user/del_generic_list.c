/*
** EPITECH PROJECT, 2022
** day01 pm
** File description:
** ex00
*/

#include <stdio.h>
#include <stdlib.h>
#include "../../include/list.h"

bool list_del_elem_at_front(teams_t *front_ptr)
{
    teams_t tmp = *front_ptr;

    if (!tmp)
        return false;
    *front_ptr = (*front_ptr)->next;
    free(tmp);
    return true;
}

bool list_del_elem_at_back(teams_t *front_ptr)
{
    teams_t tmp = *front_ptr;

    if (!tmp)
        return false;
    if ((*front_ptr)->next == NULL) {
        free(*front_ptr);
        return true;
    }
    while (tmp->next->next)
        tmp = tmp->next;
    free(tmp->next);
    tmp->next = NULL;

    return true;
}

bool list_del_elem_at_position(teams_t *front_ptr, unsigned int position)
{
    teams_t pre = *front_ptr;
    teams_t current = *front_ptr;

    if (position >= list_get_size(*front_ptr) || *front_ptr == NULL)
        return false;
    if (position == 0)
        return list_del_elem_at_front(front_ptr);
    for (unsigned int i = 0; i < position; ++i) {
        pre = current;
        current = current->next;
    }
    pre->next = current->next;
    free(current);

    return true;
}

void list_clear(teams_t *list)
{
    teams_t my_free = *list;
    teams_t next = NULL;

    while (my_free != NULL) {
        next = my_free->next;
        free(my_free);
        my_free = next;
    }
    *list = NULL;
}