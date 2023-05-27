/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** header for my linked list lib
*/

#ifndef MY_LIST
    #define MY_LIST

    typedef struct list_s {
        void *data;
        struct list_s *prev;
        struct list_s *next;
    } list_t;

    typedef void (list_callback_t)(void *);

list_t *create_list_node(void *data);
void destroy_list(list_t **head, list_callback_t *destroy);
int append_to_list(list_t **head, void *data);
int prepend_to_list(list_t **head, void *data);
int insert_to_list(list_t **head, void *data);

list_t *get_list_start(list_t *head);
list_t *get_list_end(list_t *head);
void callback_list(list_t *head, list_callback_t *callback);
void *pop_list(list_t **head, int index);

#endif /* !MY_LIST */
