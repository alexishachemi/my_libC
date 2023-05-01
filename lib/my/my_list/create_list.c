/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** create_list
*/

#include <stdlib.h>
#include "mylist.h"

list_t *create_list(void *data)
{
    list_t *node = NULL;

    if ((node = malloc(sizeof(list_t))) == NULL) {
        return NULL;
    }
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

static void destroy_rec(list_t *node, void (*destroy)(void *))
{
    if (node == NULL) {
        return;
    }
    destroy_rec(node->prev, destroy);
    destroy_rec(node->next, destroy);
    if (destroy != NULL) {
        destroy(node->data);
    }
    free(node);
}

void destroy_list(list_t **head, void (*destroy)(void *))
{
    if (head == NULL) {
        return;
    }
    destroy_rec(*head, destroy);
    *head = NULL;
}
