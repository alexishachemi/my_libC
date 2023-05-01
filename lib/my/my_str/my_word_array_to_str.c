/*
** EPITECH PROJECT, 2023
** my_word_array_to_str
** File description:
** my_word_array_to_str
*/

#include <stdlib.h>
#include "mylib.h"

static int append_str(char **str, const char *new, char *separator)
{
    char *tmp = NULL;

    tmp = my_strcat_new(*str, new, separator);
    my_free(str);
    *str = tmp;
    if (tmp == NULL) {
        return -1;
    }
    return 0;
}

char *my_word_array_to_str(char **word_array, char *separator)
{
    char *str = NULL;

    if (word_array == NULL) {
        return NULL;
    }
    if (word_array[0] == NULL) {
        return my_strdup("");
    }
    if ((str = my_strdup(word_array[0])) == NULL) {
        return NULL;
    }
    for (int i = 1; word_array[i] != NULL; i++) {
        if (append_str(&str, word_array[i], separator) == -1) {
            return NULL;
        }
    }
    return str;
}
