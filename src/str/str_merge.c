/*
** EPITECH PROJECT, 2023
** my_ls
** File description:
** my_str_merge
*/

#include "stdlib.h"
#include "mystr.h"

static void set_sizes(int **sizes, const char *left, const char *right,
const char *sep)
{
    *(sizes[0]) = my_strlen(left);
    *(sizes[1]) = my_strlen(right);
    *(sizes[2]) = sep ? my_strlen(sep) : 0;
}

// @brief Concatenate two strings with a separator
// @param left The left string
// @param right The right string
// @param sep The separator to put between the two strings, NULL if none
// @return The concatenated string (allocated), NULL on failure
char *my_str_merge(const char *left, const char *right, const char *sep)
{
    int size_left = 0, size_right = 0, size_sep = 0;
    char *str = NULL;

    if (!left && !right) {
        return NULL;
    }
    if (!left || !right) {
        return left ? my_strdup(left) : my_strdup(right);
    }
    set_sizes((int*[]){&size_left, &size_right, &size_sep}, left, right, sep);
    str = malloc(size_left + size_sep + size_right + 1);
    if (str == NULL) {
        return NULL;
    }
    my_strcpy(str, left);
    if (size_sep > 0) {
        my_strcpy(str + size_left, sep);
    }
    my_strcpy(str + size_left + size_sep, right);
    return str;
}
