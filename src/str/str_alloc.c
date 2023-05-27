/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** my_str_append
*/

#include <stdlib.h>
#include <stddef.h>
#include "mystr.h"

/// @brief Duplicate a string into a new allocated string of a given size
/// @param str string to duplicate
/// @param size size of the new string
/// @return the new string (allocated), NULL if on failure
char *my_strndup(const char *str, int size)
{
    char *new = NULL;

    if (size < 0) {
        size = my_strlen(str) + size + 1;
    }
    if (!str) {
        return NULL;
    }
    new = my_str_alloc(size, -1);
    if (!new) {
        return NULL;
    }
    my_strncpy(new, str, size);
    return new;
}

/// @brief Append a char to a string
/// @param str string to append to
/// @param c char to append
/// @return 0 if success, -1 if failure
int my_str_append(char **str, char c)
{
    char *new = NULL;
    int size = 0;

    if (!str) {
        return -1;
    }
    size = my_strlen(*str);
    new = my_strndup(*str, size + 1);
    if (!new) {
        return -1;
    }
    new[size] = c;
    new[size + 1] = '\0';
    free(*str);
    *str = new;
    return 0;
}

/// @brief Duplicate a string
/// @param str The string to duplicate
/// @return The duplicated string (allocated), NULL on failure
char *my_strdup(const char *str)
{
    char *new = NULL;

    if (!str) {
        return NULL;
    }
    new = malloc(my_strlen(str) + 1);
    if (!new) {
        return NULL;
    }
    my_strcpy(new, str);
    return new;
}

/// @brief Allocate a null terminated string of a given size
/// @param size The size of the string to allocate
/// @param fill_char The character to fill the string with
/// (negative to disable)
/// @return The allocated string, NULL if on failure
char *my_str_alloc(int size, char fill_char)
{
    char *str = NULL;

    if (size <= 0) {
        return NULL;
    }
    if ((str = malloc(size + 1)) == NULL) {
        return NULL;
    }
    str[size] = '\0';
    if (fill_char < 0) {
        return str;
    }
    for (int i = 0; i < size; i++) {
        str[i] = fill_char;
    }
    return str;
}
