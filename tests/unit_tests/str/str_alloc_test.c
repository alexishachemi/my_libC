/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_realloc_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_append, append)
{
    char *str = NULL;

    str = my_strdup("Hello");
    cr_assert_not_null(str);
    cr_assert_eq(my_str_append(&str, '!'), 0);
    cr_assert_str_eq(str, "Hello!");
    free(str);
}

Test(my_strndup, strndup)
{
    char *str = "Hello there";
    char *new = NULL;

    new = my_strndup(str, 4);
    cr_assert_not_null(new);
    cr_assert_str_eq(new, "Hell");
    free(new);
}

Test(my_strdup, dup)
{
    char *str = "helloworld";
    char *dup = NULL;

    dup = my_strdup(str);
    if (!dup) {
        cr_assert_fail();
    }
    cr_assert_str_eq(dup, "helloworld");
    free(dup);
}

Test(my_str_alloc, basic)
{
    char *str = my_str_alloc(5, 'a');

    if (!str) {
        cr_assert_fail();
    }
    cr_assert_str_eq(str, "aaaaa");
    free(str);
}
