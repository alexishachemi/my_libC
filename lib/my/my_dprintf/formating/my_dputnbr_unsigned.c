/*
** EPITECH PROJECT, 2023
** my_fputnbr_unsigned
** File description:
** my_fputnbr_unsigned
*/

#include "mylib.h"

int my_dputnbr_unsigned(int fd, unsigned int nbr)
{
    int total = 0;

    if (nbr <= 9) {
        my_dputchar(fd, 48 + nbr);
        total++;
    }
    if (nbr >= 10) {
        total += my_dputnbr(fd, nbr / 10);
        my_dputchar(fd, nbr % 10 + 48);
        total++;
    }
    return total;
}
