/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_to_str
*/

#include <stdlib.h>
#include "mystr.h"

/// @brief Convert a word array into a string
/// @param warr Word array to convert
/// @param delim Delimiter to use between each word (NULL for none)
/// @return The string (allocated), NULL on failure
char *my_warr_to_str(char **warr, char *delim)
{
    char *str = NULL;
    char *tmp = NULL;

    if (!warr) {
        return NULL;
    }
    for (int i = 0; warr[i]; i++) {
        tmp = my_str_merge(str, warr[i], delim);
        if (str) {
            free(str);
        }
        if (!tmp) {
            return NULL;
        }
        str = tmp;
    }
    return str;
}
