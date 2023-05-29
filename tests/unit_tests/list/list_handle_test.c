/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** list_handle_test
*/

#include <criterion/criterion.h>
#include "mylist.h"
#include "mytools.h"
#include "mystr.h"

Test(get_list_start, get_start)
{
    list_t *head = NULL;
    list_t *node = NULL;

    append_to_list(&head, my_strdup("Hello"));
    append_to_list(&head, my_strdup("World"));
    append_to_list(&head, my_strdup("42"));
    node = head->next->next;
    cr_assert_str_eq(node->data, "42");
    node = get_list_start(head);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "Hello");
    destroy_list(&head, free);
}

Test(get_list_end, get_end)
{
    list_t *head = NULL;
    list_t *node = NULL;

    append_to_list(&head, my_strdup("Hello"));
    append_to_list(&head, my_strdup("World"));
    append_to_list(&head, my_strdup("42"));
    node = get_list_end(head);
    cr_assert_not_null(node);
    cr_assert_str_eq(node->data, "42");
    destroy_list(&head, free);
}
