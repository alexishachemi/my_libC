/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_count_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_count, simple)
{
    cr_assert_eq(my_str_count("Hello World", 'l'), 3);
}

Test(my_str_count, empty)
{
    cr_assert_eq(my_str_count("", 'l'), 0);
}

Test(my_str_count, null)
{
    cr_assert_eq(my_str_count(NULL, 'l'), 0);
}

Test(my_str_count, multiple)
{
    char *str = "Hello World, the best number is 42 without a single doubt";

    cr_assert_eq(my_str_count(str, 'e'), 5);
}
