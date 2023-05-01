/*
** EPITECH PROJECT, 2023
** my_list
** File description:
** header for my linked list lib
*/

#ifndef MY_LIST
    #define MY_LIST

    struct list_s {
        void *data;
        struct list_s *prev;
        struct list_s *next;
    };

    typedef struct list_s list_t;

list_t *create_list(void *data);
void destroy_list(list_t **head, void (*destroy)(void *));
void callback_list(list_t **head, void (*callback)(void *),
int include_prev);
int append_to_list(list_t **head, void *data, int direction);
int push_to_list(list_t **head, void *data);
void *pop_list(list_t **head, int index);

#endif /* !MY_LIST */
