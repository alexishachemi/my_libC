/*
** EPITECH PROJECT, 2023
** my_fputbase
** File description:
** my_fputbase
*/

#include "mylib.h"

int my_dputbase(int fd, int nbr, int base, int upcase)
{
    const char* base_str = upcase ? "0123456789ABCDEF" : "0123456789abcdef";
    int nbr2 = nbr;
    int total = 0;

    if (nbr2 < 0) {
            nbr2 *= -1;
            total += my_dputchar(fd, '-');
        }
    if ((int)nbr2 / base) {
        total += my_dputbase(fd, (int)nbr2 / base, base, upcase);
    }
    total += my_dputchar(fd, base_str[nbr2 % base]);
    return total;
}
