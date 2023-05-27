/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_find
*/

#include "mystr.h"

static int find_from_end(const char *str, char c, int start)
{
    int i = start;

    while (str[i] != c) {
        if (i < 0) {
            return -1;
        }
        i--;
    }
    return i;
}

static int find_from_start(const char *str, char c, int start)
{
    int i = start;

    while (str[i] != c) {
        if (str[i] == '\0') {
            return -1;
        }
        i++;
    }
    return i;
}

/// @brief  Finds the first occurence of a char in a string
/// @param str string to search in
/// @param c  char to search
/// @param start index to start searching from
/// @return index of the first occurence of c in str, -1 if not found
int my_str_find(const char *str, char c, int start)
{
    int size = 0;

    size = my_strlen(str);
    if ((start < 0 && start * -1 >= size) || (start >= 0 && start >= size)) {
        return -1;
    }
    if (start >= 0) {
        return find_from_start(str, c, start);
    }
    return find_from_end(str, c, size + start);
}
