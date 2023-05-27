/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_nb_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_from_nb, base_10)
{
    char *str = my_str_from_nb(123, NULL);

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "123");
    free(str);
}

Test(my_str_from_nb, base_2)
{
    char *str = my_str_from_nb(123, "01");

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "1111011");
    free(str);
}

Test(my_str_from_nb, base_16)
{
    char *str = my_str_from_nb(123, "0123456789ABCDEF");

    cr_assert_not_null(str);
    cr_assert_str_eq(str, "7B");
    free(str);
}

Test(my_str_to_nb, base_10)
{
    cr_assert_eq(my_str_to_nb("1111011", "01"), 123);
    cr_assert_eq(my_str_to_nb("123", NULL), 123);
}
