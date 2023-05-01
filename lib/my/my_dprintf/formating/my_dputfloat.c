/*
** EPITECH PROJECT, 2023
** my_fputfloat
** File description:
** my_fputfloat
*/

#include "mylib.h"

int my_dputfloat(int fd, float nb, int precision)
{
    int total = 0;

    if (nb < 0) {
        my_dputchar(fd, '-');
        nb *= -1;
        total++;
    }
    total += my_dputnbr(fd, (int)nb);
    total += my_dputchar(fd, '.');
    nb -= (int)nb;
    for (int i = 0; i < precision; i++) {
        nb *= 10;
        total += my_dputchar(fd, (int)nb + '0');
        nb -= (int)nb;
    }
    return total;
}
