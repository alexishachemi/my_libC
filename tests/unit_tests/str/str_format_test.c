/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_fromat_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_format, simple)
{
    char *str = my_str_format("Hello %s", "World");

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "Hello World");
    free(str);
}

Test(my_str_format, null)
{
    char *str = my_str_format(NULL);

    cr_assert_null(str);
}

Test(my_str_format, advanced)
{
    char *format = "Hello %s, the number %d is different from %f !";
    char *formated = "Hello World, the number 42 is different from 3.140000 !";
    char *str = NULL;

    str = my_str_format(format, "World", 42, 3.14);
    cr_assert_not_null(str);
    cr_assert_str_eq(str, formated);
    free(str);
}
