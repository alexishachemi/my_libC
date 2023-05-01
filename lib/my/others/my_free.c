/*
** EPITECH PROJECT, 2023
** template_project
** File description:
** my_free
*/

#include <stdlib.h>

void my_free(void *ptr)
{
    void **data = (void **)ptr;

    if (*data != NULL) {
        free(*data);
        *data = NULL;
    }
}
