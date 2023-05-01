/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number base conversion flags
*/

#include <stdarg.h>
#include <stdio.h>
#include "mylib.h"

int dprintf_b_flag(int fd, va_list list)
{
    return my_dputbase(fd, va_arg(list, int), 2, 0);
}

int dprintf_x_flag(int fd, va_list list)
{
    return my_dputbase(fd, va_arg(list, int), 16, 0);
}

int dprintf_o_flag(int fd, va_list list)
{
    return my_dputbase(fd, va_arg(list, int), 8, 0);
}

int dprintf_capx_flag(int fd, va_list list)
{
    return my_dputbase(fd, va_arg(list, int), 16, 1);
}

int dprintf_p_flag(int fd, va_list list)
{
    int total = 0;
    int nbr = 0;
    int ptr = 0;

    ptr = (unsigned int)nbr;
    nbr = va_arg(list, int);
    total += my_dputstr(fd, "0x");
    total += my_dputbase(fd, ptr, 16, 0);
    return total;
}
