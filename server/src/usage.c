/*
** EPITECH PROJECT, 2022
** server usage
** File description:
** usage
*/

#include <unistd.h>

void usage(void)
{
    write(1, "USAGE: ./myteams_server port\n\n", 30);
    write(1,
        "\tport is the port number on which the server socket listens.\n", 61);
}
