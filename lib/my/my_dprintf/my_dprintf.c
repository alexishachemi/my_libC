/*
** EPITECH PROJECT, 2023
** my_fprintf
** File description:
** has the same behavior as the printf function but writes the output to fd
*/

#include <stdlib.h>
#include <stdarg.h>
#include "mylib.h"
#include "my_dprintf.h"

static int handle_flags(int fd, const char* format, va_list list, int i)
{
    dprintf_flag_t flags[] = {
        {'b', dprintf_b_flag},  {'c', dprintf_c_flag},
        {'u', dprintf_u_flag}, {'f', dprintf_f_flag},
        {'d', dprintf_di_flag}, {'%', dprintf_perc_flag},
        {'i', dprintf_di_flag}, {'o', dprintf_o_flag},
        {'s', dprintf_s_flag},  {'x', dprintf_x_flag},
        {'F', dprintf_f_flag},  {'p', dprintf_p_flag},
        {'X', dprintf_capx_flag}, {'W', dprintf_capw_flag},
        {'\0', NULL}
    };

    if (format[i] != '%') {
        return -1;
    }
    for (int c = 0; flags[c].ptr != NULL; c++) {
        if (format[i + 1] == flags[c].name) {
            return flags[c].ptr(fd, list);
        }
    }
    return -1;
}

int my_dprintf(int fd, const char* format, ...)
{
    va_list list;
    int total = 0;
    int tmp = 0;

    va_start(list, format);
    for (int i = 0; format[i] != '\0'; i++) {
        tmp = handle_flags(fd, format, list, i);
        if (tmp != -1) {
            total += tmp;
            i++;
        } else {
            my_dputchar(fd, format[i]);
        }
    }
    va_end(list);
    return total;
}
