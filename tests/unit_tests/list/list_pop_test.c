/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** list_pop_test
*/

#include <criterion/criterion.h>
#include "mylist.h"
#include "mystr.h"

Test(pop_list, positive_index)
{
    list_t *head = NULL;
    char *data = NULL;

    append_to_list(&head, my_strdup("Hello"));
    append_to_list(&head, my_strdup("World"));
    append_to_list(&head, my_strdup("42"));
    head = head->next;
    data = pop_list(&head, 1);
    cr_assert_str_eq(data, "42");
    cr_assert_not_null(head);
    cr_assert_str_eq(head->data, "World");
    cr_assert_not_null(head->prev);
    cr_assert_str_eq(head->prev->data, "Hello");
    cr_assert_null(head->next);
    cr_assert_null(head->prev->prev);
    destroy_list(&head, free);
}

Test(pop_list, negative_index)
{
    list_t *head = NULL;
    char *data = NULL;

    append_to_list(&head, my_strdup("Hello"));
    append_to_list(&head, my_strdup("World"));
    append_to_list(&head, my_strdup("42"));
    head = head->next;
    data = pop_list(&head, -1);
    cr_assert_str_eq(data, "Hello");
    cr_assert_not_null(head);
    cr_assert_str_eq(head->data, "World");
    cr_assert_not_null(head->next);
    cr_assert_str_eq(head->next->data, "42");
    cr_assert_null(head->prev);
    cr_assert_null(head->next->next);
    destroy_list(&head, free);
}

Test(pop_list, zero_index)
{
    list_t *head = NULL;
    char *data = NULL;

    append_to_list(&head, my_strdup("Hello"));
    append_to_list(&head, my_strdup("World"));
    append_to_list(&head, my_strdup("42"));
    head = head->next;
    data = pop_list(&head, 0);
    cr_assert_not_null(data);
    cr_assert_str_eq(data, "World");
    cr_assert_not_null(head);
    cr_assert_str_eq(head->data, "42");
    cr_assert_not_null(head->prev);
    cr_assert_str_eq(head->prev->data, "Hello");
    cr_assert_null(head->next);
    cr_assert_null(head->prev->prev);
    destroy_list(&head, free);
}
