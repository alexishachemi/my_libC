/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** my_vfstr_test
*/

#include <criterion/criterion.h>
#include "vfstr.h"

static char *call_vfstr(const char *format, ...)
{
    char *str = NULL;
    va_list list = {0};

    va_start(list, format);
    str = my_vfstr(format, list);
    va_end(list);
    return str;
}

Test(my_vfstr, simple_format)
{
    const char *format = "Hello %s !";
    char *str = "World";
    char *data = NULL;

    data = call_vfstr(format, str);
    cr_assert_str_eq(data, "Hello World !");
}
