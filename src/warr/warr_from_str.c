/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_convert
*/

#include <stdlib.h>
#include "mywarr.h"
#include "mystr.h"

static int find_next_delim(const char *str, const char *delim,
int start, bool keep_delim)
{
    int next = -1;
    int curr = 0;

    for (int i = 0; delim[i]; i++) {
        curr = my_str_find(str, delim[i], start);
        if (curr != -1 && (next == -1 || curr < next)) {
            next = curr;
        }
    }
    return next == -1 ? -1 : next + (keep_delim == true);
}

static char *get_clean_str(const char *str, const char *delim)
{
    char *new = NULL;

    if (!str || !delim) {
        return NULL;
    }
    new = my_strdup(str);
    if (!new) {
        return NULL;
    }
    my_str_clean_charset(new, delim, false);
    return new;
}

static int war_from_str_loop(char ***warr, const char *clean_str,
const char *delim, bool keep_delim)
{
    int start = 0, end = 0;
    char *tmp = NULL;

    end = find_next_delim(clean_str, delim, start, keep_delim);
    while (end != -1) {
        tmp = my_strndup(clean_str + start, end - start);
        if (!tmp || my_warr_append(warr, tmp, false) == -1) {
            return -1;
        }
        start = end + 1;
        end = find_next_delim(clean_str, delim, start, keep_delim);
    }
    tmp = my_strndup(clean_str + start - (keep_delim == true), -1);
    if (!tmp || my_warr_append(warr, tmp, false) == -1) {
        return -1;
    }
    return 0;
}

/// @brief Convert a string to a word array
/// @param str The string to convert
/// @param delim The delimiter to use
/// @param keep_delim Whether to keep the delimiter in the array
/// @return The converted word array (allocated), NULL on failure
char **my_warr_from_str(const char *str, const char *delim, bool keep_delim)
{
    char **warr = NULL;
    char *clean_str = NULL;

    clean_str = get_clean_str(str, delim);
    if (!clean_str) {
        return NULL;
    }
    warr = my_warr_alloc(0);
    if (!warr) {
        free(clean_str);
        return NULL;
    }
    if (war_from_str_loop(&warr, clean_str, delim, keep_delim) == -1) {
        my_warr_free(warr);
        free(clean_str);
        return NULL;
    }
    free(clean_str);
    return warr;
}
