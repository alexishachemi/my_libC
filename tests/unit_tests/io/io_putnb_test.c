/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_putnb_test
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "myio.h"
#include "mystr.h"

Test(my_putbase, base10)
{
    cr_redirect_stdout();
    my_putbase(42, BASE10);
    cr_assert_stdout_eq_str("42");
}

Test(my_putbase, base16)
{
    cr_redirect_stdout();
    my_putbase(42, BASE16);
    cr_assert_stdout_eq_str("2a");
}

Test(my_putbase, base2)
{
    cr_redirect_stdout();
    my_putbase(42, BASE2);
    cr_assert_stdout_eq_str("101010");
}

Test(my_putnbr, simple)
{
    cr_redirect_stdout();
    my_putnbr(42);
    cr_assert_stdout_eq_str("42");
}

Test(my_put_double, simple)
{
    cr_redirect_stdout();
    my_put_double(3.14);
    cr_assert_stdout_eq_str("3.140000");
}

Test(my_put_double, advanced)
{
    cr_redirect_stdout();
    my_put_double(578.3476);
    cr_assert_stdout_eq_str("578.347600");
}

Test(my_put_unsigned, simple)
{
    cr_redirect_stdout();
    my_put_unsigned(-42);
    cr_assert_stdout_eq_str("4294967254");
}
