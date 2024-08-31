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

Test(my_dpow, dpow)
{
    cr_assert_eq(my_dpow(2.0, 2), 4.0);
    cr_assert_eq(my_dpow(2.0, 0), 1.0);
    cr_assert_eq(my_dpow(3.5, 2), 12.25);
    cr_assert_eq(my_dpow(1.5, 3), 3.375);
    cr_assert_eq(my_dpow(0.0, 5), 0.0);
}
