/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** my_fstr
*/

#include "stddef.h"
#include "vfstr.h"

/// @brief Format a string with a variable number of arguments (printf-like)
/// @param format format string
/// @param list list of arguments
/// @return The formatted string (allocated), NULL on failure
char *my_str_format(const char *format, ...)
{
    char *str = NULL;
    va_list list = {0};

    va_start(list, format);
    str = my_vfstr(format, list);
    va_end(list);
    return str;
}
