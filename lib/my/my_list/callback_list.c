/*
** EPITECH PROJECT, 2023
** callback_list
** File description:
** callback_list
*/

#include <stdlib.h>
#include "mylist.h"

static void callback_rec(list_t *curr, void (*callback)(void *),
int direction)
{
    if (curr == NULL) {
        return;
    }
    if (direction == -1) {
        callback_rec(curr->prev, callback, direction);
    }
    callback(curr->data);
    if (direction == 1) {
        callback_rec(curr->next, callback, direction);
    }
}

void callback_list(list_t **head, void (*callback)(void *),
int include_prev)
{
    list_t *curr = *head;

    if (head == NULL || callback == NULL) {
        return;
    }
    if (include_prev) {
        callback_rec(curr->prev, callback, -1);
    }
    callback_rec(curr, callback, 1);
}
