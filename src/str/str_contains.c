/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_contains
*/

#include <stddef.h>
#include "mystr.h"

/// @brief Check if a string contains a substring
/// @param str string to search in
/// @param to_find substring to search
/// @return the index of the first occurence of to_find in str,
/// -1 if not found
int my_str_contains(const char *str, const char *to_find)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (my_str_startswith(str + i, to_find)) {
            return i;
        }
    }
    return -1;
}
