/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number conversion flags
*/

#include <stdarg.h>
#include "mystr.h"

char *fstr_di_flag(va_list list)
{
    return my_str_from_nb(va_arg(list, int), "0123456789");
}

char *fstr_f_flag(va_list list)
{
    return my_str_from_double(va_arg(list, double));
}
