/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_replace
*/

#include <stdlib.h>
#include "mystr.h"

static char *merge_strings(char *left, char *right, const char *replace_str)
{
    char *merged = NULL;
    char *tmp = NULL;

    tmp = my_str_merge(left, replace_str, NULL);
    if (!tmp) {
        free(left);
        free(right);
        return NULL;
    }
    merged = my_str_merge(tmp, right, NULL);
    free(left);
    free(right);
    free(tmp);
    return merged;
}

/// @brief Replace a substring in a string
/// @param str the string to modify
/// @param replace_str the string to replace with
/// @param start start index of the substring to replace (included)
/// @param finish end index of the substring to replace (excluded)
/// @return the new string (allocated), NULL on failure
char *my_str_replace_delim(const char *str, const char *replace_str,
int start, int finish)
{
    char *left = NULL;
    char *right = NULL;

    if (!str || !replace_str || start < 0 ||
        (finish >= 0 && start > finish)) {
        return NULL;
    }
    finish = finish < 0 ? my_strlen(str) - finish + 1 : finish;
    left = my_str_extract(str, 0, start);
    if (!left) {
        return NULL;
    }
    right = my_str_extract(str, finish, -1);
    if (!right) {
        free(left);
        return NULL;
    }
    return merge_strings(left, right, replace_str);
}

static int replace_occurence(char **new, const char *to_replace,
const char *replace_str, int size)
{
    int start = 0;
    char *tmp = NULL;

    start = my_str_contains(*new, to_replace);
    if (start == -1) {
        return 0;
    }
    tmp = my_str_replace_delim(*new, replace_str, start, start + size);
    free(*new);
    if (!tmp) {
        return -1;
    }
    *new = tmp;
    return 1;
}

/// @brief Replace a substring in a string
/// @param str the string to modify
/// @param replace_str the string to replace with
/// @param to_replace the substring to replace
/// @return the new string (allocated), NULL on failure
char *my_str_replace(const char *str, const char *to_replace,
const char *replace_str)
{
    char *new = NULL;
    int size = 0;
    int status = 1;
    bool replaced = false;

    if (!str || !to_replace || !replace_str || !(new = my_strdup(str))) {
        return NULL;
    }
    size = my_strlen(to_replace);
    while (status == 1) {
        status = replace_occurence(&new, to_replace, replace_str, size);
        if (status == 1) {
            replaced = true;
        }
    }
    if (!replaced) {
        free(new);
        return NULL;
    }
    return status == -1 ? NULL : new;
}
