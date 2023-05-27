/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** io_putnb
*/

#include "myio.h"
#include "mystr.h"

/// @brief Prints an integer to a given base to the standard output
/// @param nbr integer to print
/// @param base_string base to print the integer in
/// @return number of characters printed
int my_putbase(int nbr, const char *base_string)
{
    const char *curr_base = base_string ? base_string : BASE10;
    int nbr2 = nbr;
    int total = 0;
    int base = 0;

    base = my_strlen(curr_base);
    if (nbr2 < 0) {
        nbr2 *= (-1);
        my_putchar('-');
        total++;
    }
    if ((int)nbr2 / base) {
        total += my_putbase((int)nbr2 / base, curr_base);
    }
    my_putchar(curr_base[nbr2 % base]);
    return total;
}

/// @brief Prints a number to the standard output
/// @param nbr number to print
/// @return number of characters printed
int my_putnbr(int nbr)
{
    return my_putbase(nbr, BASE10);
}

/// @brief Prints a double to the standard output
/// @param nbr double to print
/// @return number of characters printed
int my_put_double(double nbr)
{
    int total = 0;

    total += my_putnbr((int)nbr);
    total += my_putchar('.');
    nbr -= (int)nbr;
    nbr *= 1000000;
    total += my_putnbr((int)nbr);
    return total;
}

/// @brief Prints an unsigned int
/// @param nbr unsingned int to print
/// @return number of characters printed
int my_put_unsigned(unsigned int nbr)
{
    int total = 0;

    if (nbr <= 9) {
        my_putchar(48 + nbr);
        total++;
    }
    if (nbr >= 10) {
        total += my_putnbr(nbr / 10);
        my_putchar(nbr % 10 + 48);
        total++;
    }
    return total;
}
