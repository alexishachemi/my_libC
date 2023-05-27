/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_fix_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_startswith, prefix)
{
    char *str = "hello, sir? This is a test string (?)!";

    cr_assert_eq(my_str_startswith(str, "hello"), true);
    cr_assert_eq(my_str_startswith(str, "world"), false);
}

Test(my_str_endswith, suffix)
{
    char *str = "hello, sir? This is a test string (?)!";

    cr_assert_eq(my_str_endswith(str, "!"), true);
    cr_assert_eq(my_str_endswith(str, "world"), false);
}
