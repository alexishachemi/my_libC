/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** list_pop
*/

#include <stdlib.h>
#include "mylist.h"

static void *handle_zero_index(list_t **head)
{
    list_t *tmp = NULL;
    void *data = NULL;

    data = (*head)->data;
    if ((*head)->next) {
        (*head)->next->prev = (*head)->prev;
    }
    if ((*head)->prev) {
        (*head)->prev->next = (*head)->next;
    }
    tmp = *head;
    *head = tmp->next ? tmp->next : tmp->prev;
    free(tmp);
    return data;
}

static void *handle_non_zero_index(list_t *curr, int index, int direction)
{
    void *data = NULL;

    for (int i = 0; curr && i != index; i += direction) {
        curr = direction < 0 ? curr->prev : curr->next;
    }
    if (!curr) {
        return NULL;
    }
    data = curr->data;
    if (curr->next) {
        curr->next->prev = curr->prev;
    }
    if (curr->prev) {
        curr->prev->next = curr->next;
    }
    free(curr);
    return data;
}

void *pop_list(list_t **head, int index)
{
    int direction = index < 0 ? -1 : 1;

    if (!head || !*head) {
        return NULL;
    }
    if (index == 0) {
        return handle_zero_index(head);
    }
    return handle_non_zero_index(*head, index, direction);
}
