/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_alnum_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_isalpha, alpha)
{
    char *str_true = "helloworld";
    char *str_false = "hello world 42";

    cr_assert_eq(my_str_isalpha(str_true), true);
    cr_assert_eq(my_str_isalpha(str_false), false);
}

Test(my_str_isnum, num)
{
    char *str_true = "42";
    char *str_false = "helloworld42";

    cr_assert_eq(my_str_isnum(str_true), true);
    cr_assert_eq(my_str_isnum(str_false), false);
}

Test(my_str_isalnum, alnum)
{
    char *str_true = "helloworld42";
    char *str_false = "hello world 42!";

    cr_assert_eq(my_str_isalnum(str_true), true);
    cr_assert_eq(my_str_isalnum(str_false), false);
}

Test(my_str_ischarset, charset)
{
    char *str_true = "helloworld42";
    char *str_false = "hello world 42!";
    char *charset = "helowrd42";

    cr_assert_eq(my_str_ischarset(str_true, charset), true);
    cr_assert_eq(my_str_ischarset(str_false, charset), false);
}

Test(my_str_isnumber_charset, number)
{
    char *str_true = "42";
    char *str_adv_true = "-42.78";
    char *str_false = "helloworld42";
    char *str_adv_false = "42.780.12";

    cr_assert_eq(my_str_isnumber_charset(str_true, BASE10), true);
    cr_assert_eq(my_str_isnumber_charset(str_adv_true, BASE10), true);
    cr_assert_eq(my_str_isnumber_charset(str_false, BASE10), false);
    cr_assert_eq(my_str_isnumber_charset(str_adv_false, BASE10), false);
}
