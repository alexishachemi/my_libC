/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_put
*/

#include <unistd.h>
#include "mystr.h"
#include "myio.h"

/// @brief Prints a character to the standard output
/// @param c character to print
/// @return number of characters printed
int my_putchar(char c)
{
    return write(1, &c, 1);
}

/// @brief Prints a string to the standard output
/// @param str string to print
/// @return number of characters printed
int my_putstr(char const *str)
{
    int size = 0;

    if (!str) {
        return 0;
    }
    size = my_strlen(str);
    return write(1, str, size);
}

/// @brief Prints a string to the standard output followed by a newline
/// @param str string to print
/// @return number of characters printed
int my_puts(char const *str)
{
    int size = 0;

    if (!str) {
        return 0;
    }
    size = my_strlen(str);
    return write(1, str, size) + write(1, "\n", 1);
}

/// @brief Prints a word array to the standard output
/// @param warr word array to print
/// @return number of characters printed
int my_putwarr(char **warr)
{
    int total = 0;
    int i = 0;

    if (!warr) {
        return 0;
    }
    while (warr[i]) {
        total += my_puts(warr[i++]);
    }
    return total;
}
