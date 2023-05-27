/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** mymath
*/

#ifndef MYMATH_H_
    #define MYMATH_H_
    #include <stdbool.h>

    typedef struct v2_s {
        int x;
        int y;
    } v2_t;

int my_pow(int nb, int power);
double my_dpow(double nb, int power);
int my_sqrt(int nb);
bool my_is_prime(int nb);
int my_find_prime_sup(int nb);

#endif /* !MYMATH_H_ */
