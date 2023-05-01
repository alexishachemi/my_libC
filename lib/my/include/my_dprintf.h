/*
** EPITECH PROJECT, 2023
** my_fprintf
** File description:
** my_fprintf
*/

#ifndef MY_FPRINTF_H_
    #define MY_FPRINTF_H_
    #include <stdarg.h>

    typedef struct dprintf_flag_s {
        char name;
        int (*ptr)(int fd, va_list list);
    } dprintf_flag_t;

int dprintf_b_flag(int fd, va_list list);
int dprintf_c_flag(int fd, va_list list);
int dprintf_perc_flag(int fd, va_list list);
int dprintf_u_flag(int fd, va_list list);
int dprintf_capx_flag(int fd, va_list list);
int dprintf_di_flag(int fd, va_list list);
int dprintf_f_flag(int fd, va_list list);
int dprintf_o_flag(int fd, va_list list);
int dprintf_s_flag(int fd, va_list list);
int dprintf_x_flag(int fd, va_list list);
int dprintf_p_flag(int fd, va_list list);
int dprintf_capw_flag(int fd, va_list list);

#endif /* !MY_FPRINTF_H_ */
