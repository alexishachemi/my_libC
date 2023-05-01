/*
** EPITECH PROJECT, 2023
** my_fstr
** File description:
** returns a formated string using sytax similar to printf
*/

#include <stdlib.h>
#include <stdarg.h>
#include "mylib.h"
#include "my_fstr.h"

static char *handle_flags(va_list list, char flag_char)
{
    char default_str[] = {'%', flag_char, '\0'};
    fstr_flag_t flags[] = {
        {'b', fstr_b_flag}, {'c', fstr_c_flag},
        {'f', fstr_f_flag}, {'d', fstr_di_flag},
        {'i', fstr_di_flag}, {'o', fstr_o_flag},
        {'s', fstr_s_flag}, {'x', fstr_x_flag},
        {'F', fstr_f_flag}, {'p', fstr_p_flag},
        {'X', fstr_capx_flag}, {'W', fstr_capw_flag},
        {'%', fstr_perc_flag}, {'\0', NULL}
    };

    for (int i = 0; flags[i].ptr != NULL; i++) {
        if (flags[i].name == flag_char) {
            return flags[i].ptr(list);
        }
    }
    return my_strdup(default_str);
}

static int handle_format_text(char **str, const char *format,
int start, int end)
{
    char *tmp = NULL;
    char *format_text = NULL;

    format_text = my_str_extract(format, start, end);
    if (format_text == NULL) {
        my_free(str);
        return -1;
    }
    tmp = my_strcat_new(*str, format_text, NULL);
    my_free(&format_text);
    my_free(str);
    if (tmp == NULL) {
        return -1;
    }
    *str = tmp;
    return 0;
}

static int merge_str(char **str, char **arg)
{
    char *tmp = NULL;

    tmp = my_strcat_new(*str, *arg, NULL);
    my_free(str);
    my_free(arg);
    if (tmp == NULL) {
        return -1;
    }
    *str = tmp;
    return 0;
}

static int fstr_loop(char **str, const char *format, char **arg, va_list list)
{
    int start = 0;

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] != '%') {
            continue;
        }
        if (handle_format_text(str, format, start, i) == -1) {
            return -1;
        }
        if ((*arg = handle_flags(list, format[i + 1])) == NULL) {
            my_free(str);
            return -1;
        }
        if (merge_str(str, arg) == -1) {
            return -1;
        }
        start = i + 2;
    }
    return 0;
}

char *my_fstr(const char* format, ...)
{
    va_list list;
    char *str = NULL;
    char *arg = NULL;
    short status = 0;

    if ((str = my_strdup("")) == NULL) {
        return NULL;
    }
    va_start(list, format);
    status = fstr_loop(&str, format, &arg, list);
    va_end(list);
    if (status == -1) {
        return NULL;
    }
    return str;
}
