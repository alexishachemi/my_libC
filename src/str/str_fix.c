/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_fix
*/

#include "mystr.h"

/// @brief Checks if a string starts with a prefix
/// @param str The string to check
/// @param prefix The prefix to check
/// @return true if the string starts with the prefix, false otherwise
bool my_str_startswith(const char *str, const char *prefix)
{
    if (!str || !prefix) {
        return false;
    }
    for (int i = 0; prefix[i] != '\0'; i++) {
        if (prefix[i] != str[i]) {
            return false;
        }
    }
    return true;
}

/// @brief Checks if a string ends with a suffix
/// @param str string to check
/// @param suffix suffix to check
/// @return true if the string ends with the suffix, false otherwise
bool my_str_endswith(const char *str, const char *suffix)
{
    int i = 0;
    int j = 0;

    if (!str || !suffix) {
        return false;
    }
    i = my_strlen(str);
    j = my_strlen(suffix);
    for (; j >= 0; i--, j--) {
        if (suffix[j] != str[i]) {
            return false;
        }
    }
    return true;
}
