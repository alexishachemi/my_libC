/*
** EPITECH PROJECT, 2023
** my_float_to_str
** File description:
** my_float_to_str
*/

#include <stdlib.h>
#include "mylib.h"

char *my_float_to_str(float nb)
{
    char *str = NULL;
    double decimal = nb - (int)nb;

    str = my_base_to_str((int)nb, "0123456789");
    if (str == NULL) {
        return NULL;
    }
    if (my_str_append(&str, '.') == -1) {
        my_free(&str);
        return NULL;
    }
    for (int i = 0; i < 3; i++) {
        decimal = (decimal - (int)decimal) * 10;
        if (my_str_append(&str, '0' + (int)decimal) == -1) {
            my_free(&str);
            return NULL;
        }
    }
    return str;
}
