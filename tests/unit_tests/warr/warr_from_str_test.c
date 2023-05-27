/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_convert_test
*/

#include <criterion/criterion.h>
#include "mywarr.h"

Test(my_warr_from_str, simple)
{
    const char *str = "Hello World";
    const char *delim = " ";
    char **warr = my_warr_from_str(str, delim, false);
    const char *ref[] = {"Hello", "World", NULL};

    cr_assert_not_null(warr);
    cr_assert_str_eq(warr[0], ref[0]);
    cr_assert_str_eq(warr[1], ref[1]);
    cr_assert_null(warr[2]);
    cr_assert_null(ref[2]);
    my_warr_free(warr);
}

Test(my_warr_from_str, keep_delim)
{
    const char *str = "Hello-There";
    const char *delim = "-";
    char **warr = my_warr_from_str(str, delim, true);
    const char *ref[] = {"Hello-", "There", NULL};

    cr_assert_not_null(warr);
    cr_assert_str_eq(warr[0], ref[0]);
    cr_assert_str_eq(warr[1], ref[1]);
    cr_assert_null(warr[2]);
    cr_assert_null(ref[2]);
    my_warr_free(warr);
}

Test(my_warr_from_str, advanced)
{
    const char *str = "---- \t  Hello---------\t\t\t\t\t\t\t\tWorld     42  !\t\t\t\t";
    const char *delim = " \t-";
    char **warr = my_warr_from_str(str, delim, false);
    const char *ref[] = {"Hello", "World", "42", "!", NULL};

    cr_assert_not_null(warr);
    cr_assert_str_eq(warr[0], ref[0]);
    cr_assert_str_eq(warr[1], ref[1]);
    cr_assert_str_eq(warr[2], ref[2]);
    cr_assert_str_eq(warr[3], ref[3]);
    cr_assert_null(warr[4]);
    cr_assert_null(ref[4]);
    my_warr_free(warr);
}
