/*
** EPITECH PROJECT, 2022
** B-NWP-400-PAR-4-1-myteams-wassini.bouzidi
** File description:
** to_array
*/

#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

void free_array(char **array)
{
    if (array)
        for (int i = 0; array[i] != NULL; ++i)
            free(array[i]);
    free(array);
}

static size_t get_nb_words(char *input, const char *del)
{
    size_t nb_words = 0;

    for (size_t i = 0; input[i] != '\0'; ++i)
        if (input[i] == *del)
            ++nb_words;

    return nb_words;
}

static void init_input(char *cpy_input, char *input, const char *del)
{
    size_t t = 0;

    for (size_t i = 0; input[i] != '\0'; ++i) {
        if (input[i] == ' ' && input[i + 1] == '\"')
            continue;
        cpy_input[t] = input[i];
        ++t;
    }
    cpy_input[t] = '\0';
}

bool to_array(char ***array, char *input, const char *del)
{
    size_t nb_words = 0;
    int i = 0;
    char *token = NULL;
    char cpy_input[strlen(input) + 1];

    init_input(cpy_input, input, del);
    nb_words = get_nb_words(cpy_input, del) + 1;
    token = strtok(cpy_input, del);
    (*array) = malloc(sizeof(char *) * (nb_words + 1));
    if ((*array) == NULL)
        return false;
    for (; token != NULL; ++i) {
        (*array)[i] = malloc(sizeof(char) * (strlen(token) + 1));
        if ((*array)[i] == NULL)
            return false;
        strcpy((*array)[i], token);
        token = strtok(NULL, del);
    }
    (*array)[i] = NULL;
    return array;
}
