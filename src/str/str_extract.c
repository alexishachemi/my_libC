/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_extract
*/

#include <stdlib.h>
#include "mystr.h"

char *my_str_extract(const char *str, int start, int finish)
{
    int size = 0;
    char *new = NULL;

    if (!str || start < 0 || (finish >= 0 && start > finish)) {
        return NULL;
    }
    if (finish < 0) {
        finish = my_strlen(str) - finish + 1;
    }
    size = finish - start;
    new = my_strndup(str + start, size);
    if (!new) {
        return NULL;
    }
    return new;
}
