/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** mywarr
*/

#ifndef MYWARR_H_
    #define MYWARR_H_
    #include <stdbool.h>

char **my_warr_alloc(int size);
void my_warr_free(char **warr);
char **my_warr_dup(char **warr);
char **my_warr_ndup(char **warr, int size);
int my_warr_append(char ***warr, char *str, bool duplicate_str);

int my_warr_len(char **warr);
char *my_warr_find(char **warr, const char *str);

char **my_warr_from_str(const char *str, const char *delim, bool keep_delim);
char *my_warr_to_str(char **warr, char *delim);

#endif /* !MYWARR_H_ */
