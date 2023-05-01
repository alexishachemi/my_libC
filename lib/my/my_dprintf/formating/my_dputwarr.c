/*
** EPITECH PROJECT, 2023
** need4steak
** File description:
** my_put_warr
*/

#include "mylib.h"

int my_dputwarr(int fd, char **word_array)
{
    int total = 0;

    for (int i = 0; word_array[i]; i++) {
        total += my_dputstr(fd, word_array[i]);
        total += my_dputchar(fd, '\n');
    }
    return total;
}
