/*
** EPITECH PROJECT, 2023
** my_h
** File description:
** my_h
*/

#ifndef MY_
    #define MY_

/// Macros

    #define UNUSED(var) (void)(var)
    #define STR_EQ(s1, s2) (my_strcmp(s1, s2) == 0)
    #define MIN(n, min) (n < min ? min : n)
    #define MAX(n, max) (n > max ? max : n)
    #define CLAMP(n, min, max) (MAX(MIN(n, min), max))
    #define IS_BETWEEN(n, min, max) (n >= min && n <= max)
    #define IS_ALPHA(c) ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
    #define IS_NUM(c) (c >= '0' && c <= '9')
    #define IS_ALNUM(c) (IS_ALPHA(n) || IS_NUM(n))
    #define C_IN_STR(c, str) (my_str_find(str, c, 0) != -1)

/// Prototypes

// math
float my_atof(char *arr);
int my_atoi(char const *str);
int my_compute_power_rec(int nb, int power);
int my_compute_square_root(int nb);
int my_find_prime_sup(int nb);
int my_is_prime(int nb);
void my_sort_int_array(int *arr, int size);
void my_swap_int(int *a, int *b);

// IO
int my_fd_to_fd(int src, int dest);
void my_put_float(double nbr);
int my_put_nbr_unsigned(unsigned int nbr);
int my_put_nbr(int nbr);
int my_put_printable(char* str);
int my_putbase(int nbr, int base, int upcase);
void my_putchar(char c);
int my_putstr(char const *str);
char* my_read_file_old(const char* pathname);
char *my_readfile(const char *filepath);
char *my_readfd(int fd, int size);
void my_putwarr(char **word_array);
void my_printf(const char* format, ...);
int my_str_tofile(const char *str, const char *filepath, int append);

// DIO
int my_dputbase(int fd, int nbr, int base, int upcase);
int my_dputchar(int fd, char c);
int my_dputnbr_unsigned(int fd, unsigned int nbr);
int my_dputnbr(int fd, int nb);
int my_dputstr(int fd, char *str);
int my_dputfloat(int fd, float nb, int precision);
int my_dputwarr(int fd, char **word_array);
int my_dprintf(int fd, const char* format, ...);

// string
char* my_realloc_str(char* str, int size);
char* my_revstr(char *str);
int my_str_lowcase(char *str);
int my_str_upcase(char *str);
int my_str_countchar(char *str, char c);
char *my_str_extract(const char *str, int start, int finish);
int my_str_find(const char *str, const char c, const int start);
int my_str_in(char *str, char *in_str, int case_insensitive);
int my_str_isalpha(char const* str);
int my_str_isnum(char const* str);
char *my_str_replace(char *str, char *replace_str, int start, int finish);
char **my_str_to_word_array(char *str, char *separators, int keep_sep);
char *my_strcat_new(const char *src, const char *dest, char *separator);
int my_strcmp(char const* s1, char const* s2);
char *my_strcpy(char *dest, char const *src);
char* my_strdup(const char* str);
int my_strlen(char const *str);
char *my_strncpy(char *dest, char const *src, int n);
char *my_strupcase(char *str);
int my_str_append(char **str, char c);

// To String
char *my_base_to_str(int nb, const char *base_str);
char *my_word_array_to_str(char **word_array, char *separator);
char *my_float_to_str(float nb);
char *my_fstr(const char* format, ...);

// Other
void my_free_word_array(char **word_array);
char *my_find_in_word_array(char **word_array, char *str);
int my_is_between(int val, int min, int max, int inclusive);
int my_is_in(const char c, const char* str);
void my_free(void *ptr);

#endif /* !MY_ */
