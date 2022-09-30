/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** init
*/

#include <stdbool.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>
#include <stdio.h>

bool init_socket(const char *ip, const int port, int sockfd)
{
    struct sockaddr_in remote = { 0x0 };

    remote.sin_addr.s_addr = inet_addr(ip);
    remote.sin_family = AF_INET;
    remote.sin_port = htons(port);

    if (connect(sockfd, (struct sockaddr *)&remote, sizeof(remote)) == -1) {
        perror("connect");
        return false;
    }
    return true;
}
