/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_copy_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_strcpy, copy)
{
    char *src = "helloworld";
    char dest[11];

    my_strcpy(dest, src);
    cr_assert_str_eq(dest, "helloworld");
}

Test(my_strncpy, copy)
{
    char *src = "helloworld";
    char dest[11];

    my_strncpy(dest, src, 5);
    cr_assert_str_eq(dest, "hello");
}
