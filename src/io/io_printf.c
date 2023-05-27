/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_printf
*/

#include <stdio.h>
#include <unistd.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdlib.h>
#include "mystr.h"
#include "vfstr.h"

/// @brief Prints a formatted string to the given file stream
/// @param fd file stream to write to
/// @param format format string (printf-like)
/// @param ... list of arguments
/// @return The number of characters written, -1 on failure
int my_fprintf(FILE *stream, const char *format, ...)
{
    char *str = NULL;
    va_list list = {0};
    int size = 0;

    va_start(list, format);
    str = my_vfstr(format, list);
    va_end(list);
    if (str == NULL) {
        return -1;
    }
    size = fwrite(str, sizeof(char), my_strlen(str), stream);
    free(str);
    return size;
}

/// @brief Prints a formatted string to the given file descriptor
/// @param fd file descriptor to write to
/// @param format format string (printf-like)
/// @param ... list of arguments
/// @return The number of characters written, -1 on failure
int my_dprintf(int fd, const char *format, ...)
{
    char *str = NULL;
    va_list list = {0};
    int size = 0;

    va_start(list, format);
    str = my_vfstr(format, list);
    va_end(list);
    if (str == NULL) {
        return -1;
    }
    size = write(fd, str, my_strlen(str));
    free(str);
    return size;
}

/// @brief Prints a formatted string to the standard output
/// @param format format string (printf-like)
/// @param ... list of arguments
/// @return The number of characters written, -1 on failure
int my_printf(const char *format, ...)
{
    char *str = NULL;
    va_list list = {0};
    int size = 0;

    va_start(list, format);
    str = my_vfstr(format, list);
    va_end(list);
    if (str == NULL) {
        return -1;
    }
    size = write(1, str, my_strlen(str));
    free(str);
    return size;
}
