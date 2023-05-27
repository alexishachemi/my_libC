/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_handle
*/

#include <stdlib.h>
#include "mystr.h"

/// @brief Count the number of characters in a string (without '\0')
/// @param str The string to count
/// @return The number of characters in the string
int my_strlen(const char *str)
{
    int i = 0;

    if (!str) {
        return 0;
    }
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

/// @brief Concatenate two strings (the destination string must be big enough)
/// @param dest The destination string
/// @param src The source string
/// @return The destination string
char *my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = 0;

    if (!dest || !src) {
        return dest;
    }
    i = my_strlen(dest);
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        j++;
    }
    dest[i + j] = '\0';
    return dest;
}

/// @brief Compare two strings
/// @param s1 The first string
/// @param s2 The second string
/// @return 0 if the strings are equal, a negative number if s1 < s2,
/// a positive number if s1 > s2
int my_strcmp(const char *s1, const char *s2)
{
    int i = 0;

    if (!s1 || !s2) {
        return 0;
    }
    while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i]) {
        i++;
    }
    return s1[i] - s2[i];
}

/// @brief reverse a string
/// @param str string to reverse
/// @return reversed string
char *my_revstr(char *str)
{
    char tmp = 0;
    int size = 0;

    if (!str) {
        return NULL;
    }
    size = my_strlen(str);
    for (int i = 0; i < size / 2; i++) {
        tmp = str[size - i - 1];
        str[size - i - 1] = str[i];
        str[i] = tmp;
    }
    return str;
}

/// @brief moves all characters of a string back by 1
/// (overwrites the first character)
/// @param str string to offset
/// @return offseted string
char *my_str_offset(char *str)
{
    if (!str) {
        return NULL;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = str[i + 1];
    }
    return str;
}
