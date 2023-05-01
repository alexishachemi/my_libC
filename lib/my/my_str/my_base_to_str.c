/*
** EPITECH PROJECT, 2023
** base_to_str
** File description:
** base_to_str
*/

#include <stddef.h>
#include "mylib.h"

static int base_to_str_rec(char **str, int nb, int base, const char *base_str)
{
    if ((int)nb / base) {
        if (base_to_str_rec(str, (int)nb / base, base, base_str) == -1) {
            return -1;
        }
    }
    return my_str_append(str, base_str[nb % base]);
}

char *my_base_to_str(int nb, const char *base_str)
{
    int base = 0;
    char *str = NULL;

    base = my_strlen(base_str);
    if (nb < 0) {
        nb = -nb;
        str = my_strdup("-");
    } else {
        str = my_strdup("");
    }
    if (str == NULL) {
        return NULL;
    }
    if (base_to_str_rec(&str, nb, base, base_str) == -1) {
        my_free(&str);
        return NULL;
    }
    return str;
}
