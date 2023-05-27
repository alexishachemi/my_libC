/*
** EPITECH PROJECT, 2022
** my_strupcase
** File description:
** write a function
*/

#include "mystr.h"

/// @brief  Put every letter of every word in it in uppercase
/// @param str  The string to modify
/// @return The modified string
char *my_str_upcase(char *str)
{
    if (!str) {
        return str;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_LOWER(str[i])) {
            str[i] -= 32;
        }
    }
    return str;
}

/// @brief  Put every letter of every word in it in lowercase
/// @param str  The string to modify
/// @return The modified string
char *my_str_lowcase(char *str)
{
    if (!str) {
        return str;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (IS_UPPER(str[i])) {
            str[i] += 32;
        }
    }
    return str;
}
