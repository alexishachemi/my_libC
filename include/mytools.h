/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** mytools
*/

#ifndef MYTOOLS_H_
    #define MYTOOLS_H_

    #define __GET_MACRO__(_1, _2, NAME, ...) NAME
    #define UNUSED __attribute__((unused))
    #define ASSERT_VOID(x) if (!(x)) return
    #define ASSERT_VAL(x, err) if (!(x)) return err
    #define ASSERT(...) __GET_MACRO__(__VA_ARGS__, ASSERT_VAL, ASSERT_VOID)\
    (__VA_ARGS__)
    #define SUCCESS 0
    #define FAILURE -1
    #define EXIT_F 84
    #define EXIT_S 0

    #define MIN(n, min) (n <= min ? min : n)
    #define MAX(n, max) (n >= max ? max : n)
    #define CLAMP(n, min, max) (MAX(MIN(n, min), max))
    #define IS_BETWEEN(n, min, max) (n >= min && n <= max)

#endif /* !MYTOOLS_H_ */
