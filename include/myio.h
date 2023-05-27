/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** myio
*/

#ifndef MYIO_H_
    #define MYIO_H_
    #include <stdio.h>

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

#endif /* !MYIO_H_ */
