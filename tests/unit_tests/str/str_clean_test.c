/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_clean_test
*/

#include <criterion/criterion.h>
#include "mystr.h"

Test(my_str_clean, soft_clean)
{
    char *str = my_strdup("  Hello  World  !  ");

    cr_assert_not_null(str);
    my_str_clean(str, ' ', false);
    cr_assert_str_eq(str, "Hello World !");
    free(str);
}

Test(my_str_clean, hard_clean)
{
    char *str = my_strdup("  Hello  World  !  ");

    cr_assert_not_null(str);
    my_str_clean(str, ' ', true);
    cr_assert_str_eq(str, "HelloWorld!");
    free(str);
}

Test(my_str_clean_charset, soft_clean)
{
    char *ref = "  \n\n\n\n    \t\t\t\t Hello  \t\t\t       World \n !\n ";
    char *str = my_strdup(ref);

    cr_assert_not_null(str);
    my_str_clean_charset(str, " \t\n", false);
    cr_assert_str_eq(str, "Hello World !");
    free(str);
}

Test(my_str_clean_charset, hard_clean)
{
    char *ref = "  \n\n\n\n    \t\t\t\t Hello  \t\t\t       World \n !\n ";
    char *str = my_strdup(ref);

    cr_assert_not_null(str);
    my_str_clean_charset(str, " \t\n", true);
    cr_assert_str_eq(str, "HelloWorld!");
    free(str);
}
