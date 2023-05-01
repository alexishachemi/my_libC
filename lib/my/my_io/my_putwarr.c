/*
** EPITECH PROJECT, 2023
** need4steak
** File description:
** my_put_warr
*/

#include "mylib.h"

void my_putwarr(char **word_array)
{
    for (int i = 0; word_array[i]; i++) {
        my_putstr(word_array[i]);
        my_putchar('\n');
    }
}
