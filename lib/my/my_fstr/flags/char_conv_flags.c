/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** characters conversion flags
*/

#include <stdarg.h>
#include "mylib.h"

char *fstr_c_flag(va_list list)
{
    char str[] = {'\0', '\0'};

    str[0] = va_arg(list, int);
    return my_strdup(str);
}

char *fstr_s_flag(va_list list)
{
    return my_strdup(va_arg(list, char*));
}

char *fstr_capw_flag(va_list list)
{
    return my_word_array_to_str(va_arg(list, char**), "\n");
}

char *fstr_perc_flag(va_list list)
{
    UNUSED(list);
    return my_strdup("%");
}
