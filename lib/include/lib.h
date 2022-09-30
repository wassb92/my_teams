/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** lib
*/

#pragma once

#include <time.h>
#include <stdbool.h>

char *my_getline(void);
void free_array(char **array);
char *create_uuid(void);
bool to_array(char ***array, char *input, const char *del);
char *clean_str(char *str);
time_t str_to_time(char *str);
char *get_current_time(void);
char *my_strcat(char **array);
bool is_double_quoted(char *str, char *full_request);
size_t tablen(char **array);
