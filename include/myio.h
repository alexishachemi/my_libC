/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** myio
*/

#ifndef MYIO_H_
    #define MYIO_H_
    #include <stdio.h>
    #include <stdbool.h>

int my_fprintf(FILE *stream, const char *format, ...);
int my_dprintf(int fd, const char *format, ...);
int my_printf(const char *format, ...);

int my_putchar(char c);
int my_putstr(char const *str);
int my_puts(char const *str);
int my_putwarr(char **warr);

int my_putbase(int nbr, const char *base_string);
int my_putnbr(int nbr);
int my_put_double(double nbr);
int my_put_unsigned(unsigned int nbr);

int my_fd_to_fd(int src, int dest);
char *my_readfd(int fd, int size);

char *my_file_to_str(const char *filepath);
char *my_sfile_to_str(const char *filepath);
int my_file_from_str(const char *filepath, const char *str, bool append);

#endif /* !MYIO_H_ */
