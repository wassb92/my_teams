/*
** EPITECH PROJECT, 2022
** client usage
** File description:
** usage
*/

#include <unistd.h>

void usage(void)
{
    write(1, "USAGE: ./myteams_cli ip port\n\n", 30);
    write(1, "\tip\tis the server ip address on which"
        " the server socket listens\n", 64);
    write(1, "\tport\tis the port number on which"
        " the server socket listens\n", 60);
}
