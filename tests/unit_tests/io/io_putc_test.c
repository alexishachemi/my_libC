/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_putc_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "myio.h"

Test(my_putchar, simple)
{
    cr_redirect_stdout();
    my_putchar('A');
    cr_assert_stdout_eq_str("A");
}

Test(my_putstr, simple)
{
    cr_redirect_stdout();
    my_putstr("Hello world");
    cr_assert_stdout_eq_str("Hello world");
}

Test(my_puts, simple)
{
    cr_redirect_stdout();
    my_puts("Hello world");
    cr_assert_stdout_eq_str("Hello world\n");
}

Test(my_putwarr, simple)
{
    char *warr[] = {"Hello", "World", "!", NULL};

    cr_redirect_stdout();
    my_putwarr(warr);
    cr_assert_stdout_eq_str("Hello\nWorld\n!\n");
}

Test(my_putwarr, null)
{
    cr_assert_eq(my_putwarr(NULL), 0);
}
