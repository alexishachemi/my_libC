/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_extract_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_extract, extract)
{
    char *str = "hello there; General Kenobi!";
    char *extracted = NULL;

    extracted = my_str_extract(str, 6, 11);
    if (!extracted) {
        cr_assert_fail();
    }
    cr_assert_str_eq(extracted, "there");
    free(extracted);
}
