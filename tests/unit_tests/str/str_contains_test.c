/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_contains_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_contains, contains)
{
    char *str = "hello there; General Kenobi!";

    if (!str) {
        cr_assert_fail();
    }
    cr_assert_eq(my_str_contains(str, "there"), 6);
    cr_assert_eq(my_str_contains(str, "howdy"), -1);
}
