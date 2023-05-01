/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** handle_list
*/

#include <stdlib.h>
#include "mylist.h"

static void connect_list(list_t *prev, list_t *node, list_t *next)
{
    if (node == NULL) {
        return;
    }
    if (prev) {
        node->prev = prev;
        prev->next = node;
    }
    if (next) {
        node->next = next;
        next->prev = node;
    }
}

int append_to_list(list_t **head, void *data, int direction)
{
    list_t *node = NULL;
    list_t *curr = NULL;

    if (head == NULL || (node = create_list(data)) == NULL) {
        return -1;
    }
    curr = *head;
    if (direction >= 0) {
        while (curr->next != NULL) {
            curr = curr->next;
        }
        connect_list(curr, node, curr->next);
    } else {
        while (curr->prev != NULL) {
            curr = curr->prev;
        }
        connect_list(curr->prev, node, curr);
    }
    return 0;
}

int push_to_list(list_t **head, void *data)
{
    list_t *node = NULL;
    list_t *curr = NULL;

    if (head == NULL || (node = create_list(data)) == NULL) {
        return -1;
    }
    curr = *head;
    connect_list(curr->prev, node, curr);
    *head = node;
    return 0;
}

void *pop_list(list_t **head, int index)
{
    list_t *curr = NULL;
    short rate = index >= 0 ? 1 : -1;
    void *data = NULL;

    if (head == NULL) {
        return NULL;
    }
    curr = *head;
    for (int i = 0; curr != NULL && i < index; i += rate) {
        curr = rate == 1 ? curr->next : curr->prev;
    }
    if (curr) {
        data = curr->data;
        connect_list(curr->prev, curr->next, NULL);
        free(curr);
        return data;
    }
    return NULL;
}
