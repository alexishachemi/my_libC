/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** math_v2_test
*/

#include <criterion/criterion.h>
#include "mymath.h"

Test(add_v2, simple)
{
    v2_t vector1 = {1, 2};
    v2_t vector2 = {3, 4};
    v2_t result = ADD_V2(vector1, vector2);

    cr_assert_eq(result.x, 4);
    cr_assert_eq(result.y, 6);
}

Test(sub_v2, simple)
{
    v2_t vector1 = {1, 2};
    v2_t vector2 = {3, 4};
    v2_t result = SUB_V2(vector1, vector2);

    cr_assert_eq(result.x, -2);
    cr_assert_eq(result.y, -2);
}

Test(mul_v2, simple)
{
    v2_t vector = {1, 2};
    v2_t result = MUL_V2(vector, 2);

    cr_assert_eq(result.x, 2);
    cr_assert_eq(result.y, 4);
}

Test(div_v2, simple)
{
    v2_t vector = {1, 2};
    v2_t result = DIV_V2(vector, 2);

    cr_assert_eq(result.x, 0.5);
    cr_assert_eq(result.y, 1);
}

Test(get_v2_mag, simple)
{
    v2_t vector = {3, 4};
    double mag = get_v2_mag(vector);

    cr_assert_eq(mag, 5, "mag: %f", mag);
}

Test(get_v2_distance, simple)
{
    v2_t vector1 = {3, 4};
    v2_t vector2 = {0, 0};
    double distance = get_v2_distance(vector1, vector2);

    cr_assert_eq(distance, 5, "distance: %f", distance);
}
