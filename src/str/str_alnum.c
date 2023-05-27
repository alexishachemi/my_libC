/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** str_alnum
*/

#include "mystr.h"

/// @brief  Check if a string is only composed of letters
/// @param str  The string to check
/// @return true if the string is only composed of letters, false otherwise
bool my_str_isalpha(const char *str)
{
    if (!str) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!IS_ALPHA(str[i])) {
            return false;
        }
    }
    return true;
}

/// @brief  Check if a string is only composed of digits (or '-' at the start)
/// @param str  The string to check
/// @return true if the string is only composed of digits, false otherwise
bool my_str_isnum(const char *str)
{
    if (!str) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!(IS_NUM(str[i]) || (i == 0 && str[i] == '-'))) {
            return false;
        }
    }
    return true;
}

/// @brief  Check if a string is only composed of letters and digits
/// @param str  The string to check
/// @return true if the string is only composed of letters and digits,
/// false otherwise
bool my_str_isalnum(const char *str)
{
    if (!str) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!IS_ALNUM(str[i])) {
            return false;
        }
    }
    return true;
}

/// @bried Check if a string is only composed
/// of characters from a given charset
/// @param str The string to check
/// @param charset The string of characters to check
/// @return true if the string is only composed of characters from charset,
/// false otherwise
bool my_str_ischarset(const char *str, const char *charset)
{
    if (!str || !charset) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (!C_IN_STR(str[i], charset)) {
            return false;
        }
    }
    return true;
}

/// @brief  Check if a string is only composed of a given charset
/// (or '-'/'+' at the start and '.' a single time)
/// @param str  The string to check
/// @param charset  The string of characters to check (NULL for base10)
/// @return true if the string is only composed of the charset,
/// false otherwise
bool my_str_isnumber_charset(const char *str, const char *charset)
{
    bool dot = false;
    const char *curr_charset = charset ? charset : BASE10;

    if (!str) {
        return false;
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '.' && (dot || i == 0)) {
            return false;
        }
        if (str[i] == '.' && !dot) {
            dot = true;
            continue;
        }
        if (!(C_IN_STR(str[i], curr_charset)
            || (i == 0 && C_IN_STR(str[i], "+-")))) {
            return false;
        }
    }
    return true;
}
