/*
** EPITECH PROJECT, 2022
** my_printf
** File description:
** characters conversion flags
*/

#include <stdlib.h>
#include <stdarg.h>
#include "mywarr.h"
#include "mystr.h"
#include "mytools.h"

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

char *fstr_capw_flag(UNUSED va_list list)
{
    char *tmp = NULL;

    tmp = my_warr_to_str(va_arg(list, char**), "\n");
    if (!tmp) {
        return NULL;
    }
    if (my_str_append(&tmp, '\n') == -1) {
        free(tmp);
        return NULL;
    }
    return tmp;
}

char *fstr_perc_flag(UNUSED va_list list)
{
    return my_strdup("%");
}
