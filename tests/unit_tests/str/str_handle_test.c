/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_handle_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_strlen, len)
{
    char *str = "helloworld";

    cr_assert_eq(my_strlen(str), 10);
}

Test(my_strcat, cat)
{
    char *src = "world";
    char dest[11] = "hello";

    my_strcat(dest, src);
    cr_assert_str_eq(dest, "helloworld");
}

Test(my_strcmp, cmp)
{
    char *str1 = "hello";
    char *str2 = "world";

    cr_assert_eq(my_strcmp(str1, str2) < 0, 1);
    cr_assert_eq(my_strcmp(str2, str1) > 0, 1);
    cr_assert_eq(my_strcmp(str1, str1), 0);
}

Test(my_revstr, rev)
{
    char str[11] = "helloworld";

    my_revstr(str);
    cr_assert_str_eq(str, "dlrowolleh");
}

Test(my_str_offset, offset)
{
    char str[] = "hello";

    my_str_offset(str);
    cr_assert_str_eq(str, "ello");
}
