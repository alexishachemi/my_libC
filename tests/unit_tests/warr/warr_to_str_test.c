/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_to_str_test
*/

#include <criterion/criterion.h>
#include "mywarr.h"

Test(my_warr_to_str, simple)
{
    char *warr[] = {"Hello", "World", "!", NULL};
    char *str = my_warr_to_str(warr, " ");

    cr_assert_str_eq(str, "Hello World !");
    free(str);
}

Test(my_warr_to_str, empty)
{
    char *warr[] = {NULL};
    char *str = my_warr_to_str(warr, " ");

    cr_assert_null(str);
}

Test(my_warr_to_str, null)
{
    char *str = my_warr_to_str(NULL, " ");

    cr_assert_null(str);
}

Test(my_warr_to_str, no_delim)
{
    char *warr[] = {"Hello", "World", "!", NULL};
    char *str = my_warr_to_str(warr, "");

    cr_assert_str_eq(str, "HelloWorld!");
    free(str);
}

Test(my_warr_to_str, long_delim)
{
    char *warr[] = {"Hello", "World", "!", NULL};
    char *str = my_warr_to_str(warr, "<-->");

    cr_assert_str_eq(str, "Hello<-->World<-->!");
    free(str);
}
