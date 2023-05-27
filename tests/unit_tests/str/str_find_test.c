/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_find_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_find, find)
{
    char *str = "hello, sir? This is a test string (?)!";

    if (!str) {
        cr_assert_fail();
    }
    cr_assert_eq(my_str_find(str, ',', 0), 5);
    cr_assert_eq(my_str_find(str, '?', -1), 35);
    cr_assert_eq(my_str_find(str, 'a', 10), 20);
}
