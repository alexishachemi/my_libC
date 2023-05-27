/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_copy
*/

/// @brief Copy a string into another
/// @param dest The destination string
/// @param src The source string
/// @return The destination string
char *my_strcpy(char *dest, const char *src)
{
    int i = 0;

    if (!dest || !src) {
        return dest;
    }
    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}

/// @brief Copy a string into another, up to a given size
/// @param dest The destination string
/// @param src The source string
/// @param size The maximum size to copy
/// @return The destination string
char *my_strncpy(char *dest, const char *src, int size)
{
    int i = 0;

    if (!dest || !src) {
        return dest;
    }
    while (src[i] != '\0' && i < size) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return dest;
}
