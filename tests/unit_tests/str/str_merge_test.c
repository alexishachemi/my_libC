/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_merge_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_merge, no_sep)
{
    char *str1 = "hello";
    char *str2 = "world";
    char *merged = NULL;

    merged = my_str_merge(str1, str2, 0);
    if (!merged) {
        cr_assert_fail();
    }
    cr_assert_str_eq(merged, "helloworld");
    free(merged);
}

Test(my_str_merge, sep)
{
    char *str1 = "hello";
    char *str2 = "world";
    char *sep = "<-->";
    char *merged = NULL;

    merged = my_str_merge(str1, str2, sep);
    if (!merged) {
        cr_assert_fail();
    }
    cr_assert_str_eq(merged, "hello<-->world");
    free(merged);
}
