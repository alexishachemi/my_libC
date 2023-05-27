/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** mymath
*/

#ifndef MYMATH_H_
    #define MYMATH_H_
    #include <stdbool.h>

    #define ABS(value) ((value) < 0 ? -(value) : (value))
    #define SQR(value) ((value) * (value))

    #define ADD_V2(v1, v2) ((v2_t){v1.x + v2.x, v1.y + v2.y})
    #define SUB_V2(v1, v2) ((v2_t){v1.x - v2.x, v1.y - v2.y})
    #define MUL_V2(v, s) ((v2_t){v.x * s, v.y * s})
    #define DIV_V2(v, s) ((v2_t){v.x / s, v.y / s})

    typedef struct v2_s {
        double x;
        double y;
    } v2_t;

int my_pow(int nb, int power);
double my_dpow(double nb, int power);
int my_sqrt(int nb);
double my_dsqrt(double nb);
bool my_is_prime(int nb);
int my_find_prime_sup(int nb);

v2_t get_v2_normalized(v2_t vector);
double get_v2_mag(v2_t vector);
double get_v2_distance(v2_t vector1, v2_t vector2);

#endif /* !MYMATH_H_ */
