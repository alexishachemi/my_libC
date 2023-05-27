/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** math_compute_test
*/

#include <criterion/criterion.h>
#include "mymath.h"

Test(my_pow, pow)
{
    cr_assert_eq(my_pow(2, 2), 4);
    cr_assert_eq(my_pow(2, 4), 16);
    cr_assert_eq(my_pow(15, 2), 225);
}

Test(my_sqrt, sqrt)
{
    cr_assert_eq(my_sqrt(4), 2);
    cr_assert_eq(my_sqrt(9), 3);
    cr_assert_eq(my_sqrt(16), 4);
}
