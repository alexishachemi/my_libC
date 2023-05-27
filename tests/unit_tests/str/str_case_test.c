/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_case_test
*/

#include <string.h>
#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_upcase, upcase)
{
    char *str = strdup("helloworld");

    if (!str) {
        cr_assert_fail();
    }
    cr_assert_str_eq(my_str_upcase(str), "HELLOWORLD");
    free(str);
}

Test(my_str_lowcase, lowcase)
{
    char *str = strdup("HELLOWORLD");

    if (!str) {
        cr_assert_fail();
    }
    cr_assert_str_eq(my_str_lowcase(str), "helloworld");
    free(str);
}
