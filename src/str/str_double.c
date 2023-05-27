/*
** EPITECH PROJECT, 2023
** my_float_to_str
** File description:
** my_float_to_str
*/

#include <stdlib.h>
#include "mystr.h"
#include "mymath.h"

/// @brief Convert a float to a string
/// @param nb double to convert
/// @return The converted float (allocated), NULL on failure
char *my_str_from_double(double nb)
{
    char *str = NULL;
    double decimal = nb - (int)nb;

    str = my_str_from_nb((int)nb, NULL);
    if (str == NULL) {
        return NULL;
    }
    if (my_str_append(&str, '.') == -1) {
        free(str);
        return NULL;
    }
    for (int i = 0; i < 6; i++) {
        decimal = (decimal - (int)decimal) * 10;
        if (my_str_append(&str, '0' + (int)decimal) == -1) {
            free(str);
            return NULL;
        }
    }
    return str;
}

/// @brief Convert a string to a double
/// @param str string to convert
/// @return The converted float, -1 on failure
double my_str_to_double(const char *str)
{
    const char *base = BASE10;
    int sign = 1, size = 0, i = 0;
    double nb = 0, neg = 0.1;

    if (!str || !my_str_isnumber_charset(str, BASE10)) {
        return -1;
    }
    nb = (double)my_str_to_nb(str, NULL);
    for (; str[i] && str[i] == ' '; i++);
    if (str[i] == '+' || str[i] == '-') {
        sign = str[i] == '-' ? -1 : 1;
        i++;
    }
    for (; str[i] && str[i] != '.'; i++);
    size = i + my_strlen(str + i + 1);
    for (i++; i <= size; i++, neg /= 10) {
        nb += my_str_find(base, str[i], 0) * neg;
    }
    return nb * sign;
}
