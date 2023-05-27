/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** mytools
*/

#ifndef MYTOOLS_H_
    #define MYTOOLS_H_

    #define UNUSED __attribute__((unused))
    #define ASSERT(x, err) if (!(x)) return err
    #define SUCCESS 0
    #define FAILURE 84

    #define MIN(n, min) (n < min ? min : n)
    #define MAX(n, max) (n > max ? max : n)
    #define CLAMP(n, min, max) (MAX(MIN(n, min), max))
    #define IS_BETWEEN(n, min, max) (n >= min && n <= max)

#endif /* !MYTOOLS_H_ */
