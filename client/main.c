/*
** EPITECH PROJECT, 2022
** client my_teams
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "client.h"
#include "const.h"

static bool is_usage(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0) {
        usage();
        return true;
    }
    return false;
}

static bool error_handling(int ac, char **av)
{
    if (ac == 2 && strcmp(av[1], "-help") == 0)
        return false;
    if (ac != 3)
        return true;
    return false;
}

int main(int ac, char **av)
{
    if (error_handling(ac, av))
        return ERROR;
    if (is_usage(ac, av))
        return GOOD;
    if (!client(av[1], atoi(av[2])))
        return ERROR;
    return GOOD;
}
