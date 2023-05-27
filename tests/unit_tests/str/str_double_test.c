/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_double_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_from_double, simple)
{
    double f = 3.14;
    char *str = my_str_from_double(f);
    char *ref = "3.140000";

    cr_assert_str_eq(str, ref, "expected %s, got %s\n", ref, str);
    free(str);
}

Test(my_str_from_double, advanced)
{
    double f = 578.17532;
    char *str = my_str_from_double(f);
    char *ref = "578.175320";

    cr_assert_str_eq(str, ref, "expected %s, got %s\n", ref, str);
    free(str);
}

Test(my_str_to_double, simple)
{
    char *str = "3.14";
    double f = my_str_to_double(str);
    double ref = 3.14;

    cr_assert_eq(f, ref, "expected %f, got %f\n", ref, f);
}

Test(my_str_to_double, advanced)
{
    char *str = "578.17532";
    double f = my_str_to_double(str);
    double ref = 578.17532;

    cr_assert_eq(f, ref, "expected %f, got %f\n", ref, f);
}
