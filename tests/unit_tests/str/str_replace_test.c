/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_replace_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_replace, replace)
{
    char *str = "hello [NAME]; Hi [NAME]! How are you [NAME]?";
    char *replaced = NULL;

    replaced = my_str_replace(str, "[NAME]", "BOB");
    if (!replaced) {
        cr_assert_fail();
    }
    cr_assert_str_eq(replaced, "hello BOB; Hi BOB! How are you BOB?");
    free(replaced);
}
