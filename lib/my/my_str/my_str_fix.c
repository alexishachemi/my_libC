/*
** EPITECH PROJECT, 2023
** my_str_fix
** File description:
** my_str_fix
*/

#include "mylib.h"

int my_str_startswith(const char *str, const char *prefix)
{
    if (!str || !prefix) {
        return 0;
    }
    for (int i = 0; prefix[i] != '\0'; i++) {
        if (prefix[i] != str[i]) {
            return 0;
        }
    }
    return 1;
}

int my_str_endswith(const char *str, const char *suffix)
{
    int i = 0;
    int j = 0;
    if (!str || !suffix) {
        return 0;
    }
    i = my_strlen(str);
    j = my_strlen(suffix);
    while (j >= 0) {
        if (suffix[j] != str[i]) {
            return 0;
        }
        i--;
        j--;
    }
    return 1;
}
