/*
** EPITECH PROJECT, 2022
** myftp
** File description:
** const
*/

#pragma once

#define _XOPEN_SOURCE

#define PUT_ERROR(msg)                                                       \
    fprintf(stderr, "\033[1;31m/******************/\033[0m\n"                \
                    "\033[1;31mERROR :\033[0m\n"                             \
                    "File : %s\n"                                            \
                    "Line : %u\n"                                            \
                    "Function : %s\n"                                        \
                    "Message : %s\n\033[1;31m/******************/\033[0m\n", \
        __FILE__, __LINE__, __FUNCTION__, msg);

#define MAX_NAME_LENGTH 32
#define MAX_DESCRIPTION_LENGTH 255
#define MAX_BODY_LENGTH 512
#define MAX_CONNECTIONS 64
#define PADDING_ARRAY 76
#define TIMESTAMP_LENGTH 25
#define LIST_SIZE sizeof(struct list_s)

/* -------------------------------- */
/*            Const var             */

static const unsigned char GOOD = 0;
static const unsigned char ERROR = 84;
static const unsigned char BACKLOG = 64;
static const char FAIL = -1;
static const char *INPUT_DEL = "\"";
static const char *RESPONSE_DEL = "`";
static const char *LOCALHOST = "127.0.0.1";
static const char *USERNAME = "Anonymous";
static const unsigned long DATA_BUFFER = 4096;

typedef enum statement_e {
    FALSE,
    TRUE,
    BREAK,
    CONTINUE,
} statement_t;