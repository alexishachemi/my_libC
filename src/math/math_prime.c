/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** math_prime
*/

#include "mymath.h"

/// @brief Check if a number is prime
/// @param nb The number to check
/// @return true if the number is prime, false otherwise
bool my_is_prime(int nb)
{
    int i = 2;

    while (i <= nb / 2) {
        if (nb % i == 0) {
            return false;
        }
        i++;
    }
    return true;
}

/// @brief Find the next prime number
/// @param nb The number to start from
/// @return The next prime number
int my_find_prime_sup(int nb)
{
    while (!my_is_prime(nb)) {
        nb++;
    }
    return nb;
}
