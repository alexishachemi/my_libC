/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number conversion flags
*/

#include <stdarg.h>
#include "mylib.h"

int dprintf_di_flag(int fd, va_list list)
{
    return my_dputnbr(fd, va_arg(list, int));
}

int dprintf_f_flag(int fd, va_list list)
{
    return my_dputfloat(fd, va_arg(list, double), 6);
}

int dprintf_u_flag(int fd, va_list list)
{
    return my_dputnbr_unsigned(fd, va_arg(list, int));
}
