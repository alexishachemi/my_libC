/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** warr_handle_test
*/

#include <criterion/criterion.h>
#include "mywarr.h"

Test(my_warr_len, len)
{
    char *warr[] = {"Hello", "World", NULL};
    int len = 0;

    len = my_warr_len(warr);
    cr_assert_eq(len, 2);
}
