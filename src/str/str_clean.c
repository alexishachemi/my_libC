/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_clean
*/

#include <stddef.h>
#include "mystr.h"

static bool clean_sides(char *str, const char *set, int *size)
{
    bool cleaned = false;

    while ((*size = my_strlen(str)) > 1 && C_IN_STR(str[0], set)) {
        my_str_offset(str);
        cleaned = true;
    }
    while ((*size = my_strlen(str)) > 1 && C_IN_STR(str[*size - 1], set)) {
        my_str_offset(str + *size - 1);
        cleaned = true;
    }
    return cleaned;
}

/// @brief Cleans a string from a given reference
/// @param str string to clean
/// @param ref reference to clean from
/// @param hard_clean if true, will fully remove all reference char
/// otherwise will fully remove them from the start and end of the string
/// and replace all multiple reference char by a single one
/// @return true if it cleaned the string, false otherwise
bool my_str_clean(char *str, char c, bool hard_clean)
{
    int size = 0;
    bool cleaned = false;
    char set[2] = {c, '\0'};

    if (!str) {
        return NULL;
    }
    cleaned = clean_sides(str, set, &size);
    for (int i = 0; str[i] && size > 1; i++) {
        while ((str[i] == c && str[i + 1] == c)
            || (str[i] == c && hard_clean)) {
            my_str_offset(str + i);
            size = my_strlen(str);
            cleaned = true;
        }
    }
    return cleaned;
}

/// @brief Cleans a string from a given charset
/// @param str string to clean
/// @param charset charset to clean from
/// @param hard_clean if true, will fully remove all reference char
/// otherwise will fully remove them from the start and end of the string
/// and replace all multiple reference char by a single one
/// @return true if it cleaned the string, false otherwise
bool my_str_clean_charset(char *str, const char *charset, bool hard_clean)
{
    int size = 0;
    bool cleaned = false;

    if (!str || !charset) {
        return NULL;
    }
    cleaned = clean_sides(str, charset, &size);
    for (int i = 0; str[i] && size > 1; i++) {
        while ((C_IN_STR(str[i], charset) && C_IN_STR(str[i + 1], charset))
            || (C_IN_STR(str[i], charset) && hard_clean)) {
            my_str_offset(str + i);
            size = my_strlen(str);
            cleaned = true;
        }
    }
    return cleaned;
}
