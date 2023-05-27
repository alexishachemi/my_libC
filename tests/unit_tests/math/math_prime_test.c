/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** math_prime_test
*/

#include <criterion/criterion.h>
#include "mymath.h"

Test(my_is_prime, prime)
{
    cr_assert_eq(my_is_prime(17), true);
    cr_assert_eq(my_is_prime(8), false);
    cr_assert_eq(my_is_prime(5), true);
    cr_assert_eq(my_is_prime(14), false);
    cr_assert_eq(my_is_prime(23), true);
    cr_assert_eq(my_is_prime(10), false);
    cr_assert_eq(my_is_prime(29), true);
    cr_assert_eq(my_is_prime(12), false);
    cr_assert_eq(my_is_prime(19), true);
    cr_assert_eq(my_is_prime(15), false);
}

Test(my_find_prime_sup, prime_sup)
{
    cr_assert_eq(my_find_prime_sup(4), 5);
    cr_assert_eq(my_find_prime_sup(10), 11);
    cr_assert_eq(my_find_prime_sup(15), 17);
    cr_assert_eq(my_find_prime_sup(21), 23);
    cr_assert_eq(my_find_prime_sup(25), 29);
    cr_assert_eq(my_find_prime_sup(30), 31);
    cr_assert_eq(my_find_prime_sup(35), 37);
    cr_assert_eq(my_find_prime_sup(40), 41);
    cr_assert_eq(my_find_prime_sup(45), 47);
    cr_assert_eq(my_find_prime_sup(50), 53);
}
