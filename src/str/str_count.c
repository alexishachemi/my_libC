/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_count
*/

#include "mystr.h"

/// @brief Count the number of occurences of a character in a string
/// @param str string to count in
/// @param c character to count
/// @return The number of occurences
int my_str_count(const char *str, char c)
{
    int count = 0;

    if (!str) {
        return 0;
    }
    for (int i = 0; str[i]; i++) {
        if (str[i] == c) {
            count++;
        }
    }
    return count;
}
