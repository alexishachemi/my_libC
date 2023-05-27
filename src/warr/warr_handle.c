/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_handle
*/

#include <stddef.h>
#include "mystr.h"

/// @brief Get the length of a word array
/// @param warr The word array
/// @return The length of the word array
int my_warr_len(char **warr)
{
    int i = 0;

    if (!warr) {
        return 0;
    }
    while (warr[i]) {
        i++;
    }
    return i;
}

/// @brief Find a string in a word array
/// @param warr Word array to search in
/// @param str String to search for
/// @return The string if found, NULL otherwise
char *my_warr_find(char **warr, const char *str)
{
    for (int i = 0; warr[i]; i++) {
        if (my_strcmp(warr[i], str) == 0) {
            return warr[i];
        }
    }
    return NULL;
}
