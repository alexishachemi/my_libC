/*
** EPITECH PROJECT, 2023
** my_fstr
** File description:
** my_fstr
*/

#ifndef MY_FSTR_H_
    #define MY_FSTR_H_
    #include <stdarg.h>

    typedef struct fstr_flag_s {
        char name;
        char *(*ptr)(va_list);
    } fstr_flag_t;

char *fstr_b_flag(va_list list);
char *fstr_c_flag(va_list list);
char *fstr_perc_flag(va_list list);
char *fstr_capx_flag(va_list list);
char *fstr_di_flag(va_list list);
char *fstr_f_flag(va_list list);
char *fstr_o_flag(va_list list);
char *fstr_s_flag(va_list list);
char *fstr_x_flag(va_list list);
char *fstr_p_flag(va_list list);
char *fstr_capw_flag(va_list list);

char *my_vfstr(const char* format, va_list list);

#endif /* !MY_FSTR_H_ */
