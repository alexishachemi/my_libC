/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** number base conversion flags
*/

#include <stdarg.h>
#include <stdio.h>
#include "mylib.h"

char *fstr_b_flag(va_list list)
{
    return my_base_to_str(va_arg(list, int), "01");
}

char *fstr_x_flag(va_list list)
{
    return my_base_to_str(va_arg(list, int), "0123456789abcdef");
}

char *fstr_o_flag(va_list list)
{
    return my_base_to_str(va_arg(list, int), "01234567");
}

char *fstr_capx_flag(va_list list)
{
    return my_base_to_str(va_arg(list, int), "0123456789ABCDEF");
}

char *fstr_p_flag(va_list list)
{
    char *str = NULL;
    char *nb_str = NULL;

    nb_str = my_base_to_str(va_arg(list, int), "0123456789abcdef");
    if (nb_str == NULL) {
        return NULL;
    }
    str = my_strcat_new("0x", nb_str, NULL);
    my_free(&nb_str);
    return str;
}
