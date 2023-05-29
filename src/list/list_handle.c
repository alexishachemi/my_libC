/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** handle_list
*/

#include <stdlib.h>
#include "mytools.h"
#include "mylist.h"

list_t *get_list_start(list_t *head)
{
    list_t *curr = NULL;

    if (!head) {
        return NULL;
    }
    curr = head;
    while (curr->prev) {
        curr = curr->prev;
    }
    return curr;
}

list_t *get_list_end(list_t *head)
{
    list_t *curr = NULL;

    if (!head) {
        return NULL;
    }
    curr = head;
    while (curr->next) {
        curr = curr->next;
    }
    return curr;
}

void callback_list(list_t *head, list_callback_t *callback)
{
    list_t *curr = NULL;

    if (!head || !callback) {
        return;
    }
    curr = get_list_start(head);
    while (curr) {
        callback(curr->data);
        curr = curr->next;
    }
}
