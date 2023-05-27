/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** math_v2
*/

#include "mymath.h"

/// @brief Get the magnitude of a vector2
/// @param vector vector2 to get the magnitude of
/// @return magnitude of the vector2
double get_v2_mag(v2_t vector)
{
    return my_dsqrt(SQR(vector.x) + SQR(vector.y));
}

/// @brief Get the normalized vector2 of a vector2
/// @param vector vector2 to get the normalized vector2 of
/// @return normalized vector2 of the vector2
v2_t get_v2_normalized(v2_t vector)
{
    double mag = 0;

    mag = get_v2_mag(vector);
    return DIV_V2(vector, mag);
}

/// @brief Get the distance between two vector2
/// @param vector1 first vector2
/// @param vector2 second vector2
/// @return distance between the two vector2
double get_v2_distance(v2_t vector1, v2_t vector2)
{
    return get_v2_mag(SUB_V2(vector1, vector2));
}
