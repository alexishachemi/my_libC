/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_from_nb
*/

#include <stdlib.h>
#include "mystr.h"
#include "mymath.h"

static int str_from_nb_rec(char **str, int nb, int base, const char *base_str)
{
    if ((int)nb / base) {
        if (str_from_nb_rec(str, (int)nb / base, base, base_str) == -1) {
            return -1;
        }
    }
    return my_str_append(str, base_str[nb % base]);
}

/// @brief Convert an number to a string in a given base
/// @param nb number to convert
/// @param base_str string of the base (NULL for base 10)
/// @return The converted number (allocated), NULL on failure
char *my_str_from_nb(int nb, const char *base_str)
{
    const char *curr_base_str = base_str ? base_str : "0123456789";
    int base = 0;
    char *str = NULL;

    base = my_strlen(curr_base_str);
    if (nb < 0) {
        nb = -nb;
        str = my_strdup("-");
    } else {
        str = my_strdup("");
    }
    if (str == NULL) {
        return NULL;
    }
    if (str_from_nb_rec(&str, nb, base, curr_base_str) == -1) {
        free(str);
        return NULL;
    }
    return str;
}

/// @brief Convert a string to an integer
/// @param str string to convert
/// @param base_str string of the base (NULL for base 10)
/// @return The converted number, -1 on failure
int my_str_to_nb(const char *str, const char *base_str)
{
    const char *curr_base_str = base_str ? base_str : "0123456789";
    int size = 0, sign = 1, base = 0, nb = 0;
    int i = 0;

    if (!str || !my_str_isnumber_charset(str, curr_base_str)) {
        return -1;
    }
    base = my_strlen(curr_base_str);
    for (; str[size] && str[size] != '.'; size++);
    for (; str[i] && str[i] == ' '; i++);
    if (str[i] == '-') {
        i++;
        sign = -1;
    }
    for (; i < size; i++) {
        nb += my_str_find(curr_base_str, str[i], 0)
        * my_pow(base, size - i - 1);
    }
    return nb * sign;
}
