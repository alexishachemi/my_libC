/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** my_str_append
*/

#include <stddef.h>
#include "mylib.h"

int my_str_append(char **str, char c)
{
    char *tmp = NULL;
    char c_str[] = {c, '\0'};

    tmp = my_strcat_new(*str, c_str, NULL);
    if (tmp == NULL) {
        return -1;
    }
    my_free(str);
    *str = tmp;
    return 0;
}
