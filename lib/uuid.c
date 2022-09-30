/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** uuid
*/

#include <stdlib.h>
#include <stdio.h>
#include <uuid/uuid.h>

char *create_uuid(void)
{
    static char uuid[UUID_STR_LEN];
    uuid_t binuuid;

    uuid_generate_random(binuuid);
    uuid_unparse(binuuid, uuid);
    return uuid;
}
