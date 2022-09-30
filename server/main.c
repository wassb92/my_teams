/*
** EPITECH PROJECT, 2022
** server my_teams
** File description:
** main
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "server.h"
#include "teams.h"
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
    if (ac != 2)
        return true;
    return false;
}

int main(int ac, char **av)
{
    server_t serv;
    int server_fd = 0;

    if (error_handling(ac, av))
        return ERROR;
    if (is_usage(ac, av))
        return GOOD;
    server_fd = create_tcp_server(atoi(av[1]));
    if (server_fd == FAIL)
        return ERROR;
    memset(&serv, 0, sizeof(server_t));
    init_server(&serv, server_fd);
    if (!server(&serv, &server_fd))
        return ERROR;
    return GOOD;
}
