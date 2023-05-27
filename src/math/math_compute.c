/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** my_compute
*/

#include "mymath.h"

/// @brief Compute the power of a number
/// @param nb The number to compute
/// @param power The power to compute
/// @return The result of the computation
int my_pow(int nb, int power)
{
    int pow = 1;

    for (int i = 0; i < power; i++) {
        pow *= nb;
    }
    return pow;
}

/// @brief Compute the power of a double
/// @param nb The double to compute
/// @param power The power to compute
/// @return The result of the computation
double my_dpow(double nb, int power)
{
    double pow = 0;

    for (int i = 0; i < power; i++) {
        pow *= nb;
    }
    return pow;
}

/// @brief Compute the square root of a number
/// @param nb The number to compute
/// @return The result of the computation
int my_sqrt(int nb)
{
    int i = 0;

    while (i * i < nb) {
        i++;
    }
    return i;
}

/// @brief Compute the square root of a double
/// @param nb The double to compute
/// @return The result of the computation
double my_dsqrt(double nb)
{
    double i = 0;

    while (i * i < nb) {
        i++;
    }
    return i;
}
