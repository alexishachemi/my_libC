/*
** EPITECH PROJECT, 2023
** my_fputnbr
** File description:
** my_fputnbr
*/

#include "mylib.h"

int my_dputnbr(int fd, int nb)
{
    int total = 0;

    if (nb < 0) {
        my_dputchar(fd, '-');
        nb *= -1;
        total++;
    }
    if (nb >= 10) {
        total += my_dputnbr(fd, nb / 10);
        total += my_dputnbr(fd, nb % 10);
    } else {
        total += my_dputchar(fd, nb + '0');
    }
    return total;
}
