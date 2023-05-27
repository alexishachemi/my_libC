/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_alloc_test
*/

#include <criterion/criterion.h>
#include "mywarr.h"
#include "mystr.h"

Test(my_warr_alloc, alloc)
{
    char **warr = NULL;

    warr = my_warr_alloc(1);
    cr_assert_not_null(warr);
    my_warr_free(warr);
}

Test(my_warr_dup, dup)
{
    char *warr[] = {"Hello", "World", NULL};
    char **dup = NULL;

    dup = my_warr_dup(warr);
    cr_assert_not_null(dup);
    cr_assert_str_eq(dup[0], "Hello");
    cr_assert_str_eq(dup[1], "World");
    cr_assert_null(dup[2]);
    my_warr_free(dup);
}

Test(my_warr_ndup, ndup)
{
    char *warr[] = {"Hello", "World", "42", NULL};
    char **dup = NULL;

    dup = my_warr_ndup(warr, 1);
    cr_assert_not_null(dup);
    cr_assert_str_eq(dup[0], "Hello");
    cr_assert_null(dup[1]);
    my_warr_free(dup);
}

Test(my_warr_append, duplicate)
{
    char *ref[] = {"Hello", "World", NULL};
    char **warr = NULL;

    warr = my_warr_dup(ref);
    cr_assert_not_null(warr);
    cr_assert_eq(my_warr_append(&warr, "42", true), 0);
    cr_assert_str_eq(warr[0], "Hello");
    cr_assert_str_eq(warr[1], "World");
    cr_assert_str_eq(warr[2], "42");
    cr_assert_null(warr[3]);
    my_warr_free(warr);
}

Test(my_warr_append, no_duplicate)
{
    char *ref[] = {"Hello", "World", NULL};
    char **warr = NULL;
    char *str = NULL;
    
    str = my_strdup("42");
    cr_assert_not_null(str);
    warr = my_warr_dup(ref);
    cr_assert_not_null(warr);
    cr_assert_eq(my_warr_append(&warr, str, false), 0);
    cr_assert_str_eq(warr[0], "Hello");
    cr_assert_str_eq(warr[1], "World");
    cr_assert_str_eq(warr[2], "42");
    cr_assert_null(warr[3]);
    cr_assert_eq(str, warr[2]);
    my_warr_free(warr);
}
