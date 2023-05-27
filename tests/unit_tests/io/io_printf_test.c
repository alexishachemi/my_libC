/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_printf_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "myio.h"

Test(my_printf, no_format)
{
    cr_redirect_stdout();
    my_printf("Hello, world!\n");
    cr_assert_stdout_eq_str("Hello, world!\n");
}

Test(my_printf, char_format)
{
    cr_redirect_stdout();
    my_printf("Hello, %c!\n", 'W');
    cr_assert_stdout_eq_str("Hello, W!\n");
}

Test(my_printf, string_format)
{
    cr_redirect_stdout();
    my_printf("Hello, %s!\n", "World");
    cr_assert_stdout_eq_str("Hello, World!\n");
}

Test(my_printf, word_array_format)
{
    const char *warr[] = {"Hello", "World", "!", NULL};

    cr_redirect_stdout();
    my_printf("Hello %W!\n", warr);
    cr_assert_stdout_eq_str("Hello Hello\nWorld\n!\n!\n");
}

Test(my_printf, all_flags)
{
    const char *warr[] = {"Hello", "World", "!", NULL};

    cr_redirect_stdout();
    my_printf("Hello, %c %s %W %f %d %x %b %p!\n", 'W', "World", warr, 3.14, 42, 42, 42, NULL);
    cr_assert_stdout_eq_str("Hello, W World Hello\nWorld\n!\n 3.140000 42 2a 101010 0x0!\n");
}
