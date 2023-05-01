/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** characters conversion flags
*/

#include <stdarg.h>
#include "mylib.h"

int dprintf_c_flag(int fd, va_list list)
{
    return my_dputchar(fd, va_arg(list, int));
}

int dprintf_s_flag(int fd, va_list list)
{
    return my_dputstr(fd, va_arg(list, char*));
}

int dprintf_capw_flag(int fd, va_list list)
{
    return my_dputwarr(fd, va_arg(list, char**));
}

int dprintf_perc_flag(int fd, va_list list)
{
    UNUSED(list);
    return my_dputchar(fd, '%');
}
