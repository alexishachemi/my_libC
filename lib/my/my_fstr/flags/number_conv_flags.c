/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number conversion flags
*/

#include <stdarg.h>
#include "mylib.h"

char *fstr_di_flag(va_list list)
{
    return my_base_to_str(va_arg(list, int), "0123456789");
}

char *fstr_f_flag(va_list list)
{
    return my_float_to_str(va_arg(list, double));
}
