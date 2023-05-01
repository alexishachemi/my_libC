/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** my_find_in_word_array
*/

#include <stdlib.h>
#include "mylib.h"

char *my_find_in_word_array(char **word_array, char *str)
{
    if (word_array == NULL) {
        return NULL;
    }
    for (int i = 0; word_array[i]; i++) {
        if (STR_EQ(word_array[i], str)) {
            return word_array[i];
        }
    }
    return NULL;
}
