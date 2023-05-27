/*
** EPITECH PROJECT, 2023
** my_libC
** File description:
** mystr
*/

#ifndef MYSTR_H_
    #define MYSTR_H_
    #include <stdbool.h>

    #define BASE2 "01"
    #define BASE10 "0123456789"
    #define BASE16 "0123456789abcdef"
    #define C_IN_STR(c, str) (my_str_find(str, c, 0) != -1)
    #define STR_EQ(str1, str2) (my_strcmp(str1, str2) == 0)
    #define IS_LOWER(c) (c >= 'a' && c <= 'z')
    #define IS_UPPER(c) (c >= 'A' && c <= 'Z')
    #define IS_ALPHA(c) (IS_LOWER(c) || IS_UPPER(c))
    #define IS_NUM(c) (c >= '0' && c <= '9')
    #define IS_ALNUM(c) (IS_ALPHA(c) || IS_NUM(c))

bool my_str_isalpha(char const *str);
bool my_str_isnum(char const *str);
bool my_str_isalnum(char const *str);
bool my_str_ischarset(const char *str, const char *charset);
bool my_str_isnumber_charset(const char *str, const char *charset);
bool my_str_startswith(const char *str, const char *prefix);
bool my_str_endswith(const char *str, const char *suffix);

char *my_str_upcase(char *str);
char *my_str_lowcase(char *str);
char *my_strcat(char *dest, const char *src);
char *my_revstr(char *str);
char *my_strcpy(char *dest, char const *src);
int my_strcmp(const char *s1, const char *s2);
char *my_str_offset(char *str);
int my_str_append(char **str, char c);
bool my_str_clean(char *str, char c, bool hard_clean);
bool my_str_clean_charset(char *str, const char *charset, bool hard_clean);

char *my_str_merge(const char *left, const char *right, const char *sep);
int my_strlen(char const *str);
char *my_strncpy(char *dest, const char *src, int size);
int my_str_find(const char *str, char c, int start);
int my_str_contains(const char *str, const char *to_find);
char *my_strdup(const char *str);
char *my_str_alloc(int size, char fill_char);
char *my_strndup(const char *str, int size);
char *my_str_extract(const char *str, int start, int finish);
int my_str_count(const char *str, char c);

char *my_str_replace_delim(const char *str, const char *replace_str,
int start, int finish);
char *my_str_replace(const char *str, const char *to_replace,
const char *replace_str);
char *my_str_format(const char *format, ...);
int my_str_to_nb(const char *str, const char *base_str);
char *my_str_from_nb(int nb, const char *base_str);
char *my_str_from_double(double nb);
double my_str_to_double(const char *str);

#endif /* !MYSTR_H_ */
