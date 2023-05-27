/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_alloc
*/

#include <stdlib.h>
#include "mywarr.h"
#include "mystr.h"

/// @brief Allocate an empty NULL terminated word array of a given size
/// @param size Size of the array
/// @return The allocated array, NULL on failure
char **my_warr_alloc(int size)
{
    char **warr = NULL;

    if (size < 0) {
        return NULL;
    }
    warr = malloc(sizeof(char *) * (size + 1));
    if (!warr) {
        return NULL;
    }
    for (int i = 0; i < size + 1; i++) {
        warr[i] = NULL;
    }
    return warr;
}

/// @brief Free a word array
/// @param warr The word array to free
void my_warr_free(char **warr)
{
    if (!warr) {
        return;
    }
    for (int i = 0; warr[i]; i++) {
        free(warr[i]);
    }
    free(warr);
}

/// @brief Duplicate a word array to a given size
/// @param warr The word array to duplicate
/// @param size The size of the new word array
/// @return The duplicated word array (allocated), NULL on failure
char **my_warr_ndup(char **warr, int size)
{
    char **new = NULL;

    if (!warr || size < 0) {
        return NULL;
    }
    new = my_warr_alloc(size);
    if (!new) {
        return NULL;
    }
    for (int i = 0; warr[i] && i < size; i++) {
        new[i] = my_strdup(warr[i]);
        if (!new[i]) {
            my_warr_free(new);
            return NULL;
        }
    }
    return new;
}

/// @brief Duplicate a word array
/// @param warr The word array to duplicate
/// @return The duplicated word array (allocated), NULL on failure
char **my_warr_dup(char **warr)
{
    int size = 0;

    if (!warr) {
        return NULL;
    }
    size = my_warr_len(warr);
    return my_warr_ndup(warr, size);
}

/// @brief Append a string to a word array
/// @param warr The word array to append to
/// @param str The string to append
/// @param duplicate_str If true, the string will be duplicated,
/// else it will be used as is
/// @return 0 if success, -1 if failure
int my_warr_append(char ***warr, char *str, bool duplicate_str)
{
    char **new = NULL;
    int size = 0;

    if (!warr || !str) {
        return -1;
    }
    size = my_warr_len(*warr);
    new = my_warr_ndup(*warr, size + 1);
    if (!new) {
        return -1;
    }
    new[size] = duplicate_str ? my_strdup(str) : str;
    if (!new[size]) {
        my_warr_free(new);
        return -1;
    }
    my_warr_free(*warr);
    *warr = new;
    return 0;
}
