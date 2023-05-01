##
## EPITECH PROJECT, 2022
## Lib Makefile
## File description:
## makefile for my library
##

CFLAGS += -Imy/include/ -W -Wall -Wextra -pedantic

STR	=	my_revstr.c\
		my_str_isalpha.c\
		my_str_isnum.c\
		my_str_to_word_array.c\
		my_strcat_new.c\
		my_strcmp.c\
		my_strcpy.c\
		my_strdup.c\
		my_strlen.c\
		my_strncpy.c\
		my_str_countchar.c\
		my_realloc_str.c\
		my_str_in.c\
		my_str_append.c\
		my_str_extract.c\
		my_str_find.c\
		my_str_fix.c\
		my_str_case.c\
		my_base_to_str.c\
		my_word_array_to_str.c\
		my_float_to_str.c\

MAT	=	my_compute_power_rec.c\
		my_compute_square_root.c\
		my_find_prime_sup.c\
		my_is_prime.c\
		my_sort_int_array.c\
		my_swap_int.c\
		my_atoi.c\
		my_atof.c\

IO	=	my_put_float.c\
		my_put_nbr_unsigned.c\
		my_put_nbr.c\
		my_put_printable.c\
		my_putbase.c\
		my_putchar.c\
		my_putstr.c\
		my_putwarr.c\
		my_readfile.c\
		my_read_file_old.c\
		my_readfd.c\
		my_fd_to_fd.c\
		my_str_tofile.c\

SRC	=	my_dprintf/formating/my_dputbase.c\
		my_dprintf/formating/my_dputchar.c\
		my_dprintf/formating/my_dputnbr.c\
		my_dprintf/formating/my_dputstr.c\
		my_dprintf/formating/my_dputnbr_unsigned.c\
		my_dprintf/formating/my_dputfloat.c\
		my_dprintf/formating/my_dputwarr.c\
		my_dprintf/flags/base_conv_flags.c\
		my_dprintf/flags/char_conv_flags.c\
		my_dprintf/flags/number_conv_flags.c\
		my_dprintf/my_dprintf.c\
		my_printf/flags/base_conv_flags.c\
		my_printf/flags/char_conv_flags.c\
		my_printf/flags/number_conv_flags.c\
		my_printf/my_printf.c\
		my_fstr/flags/base_conv_flags.c\
		my_fstr/flags/char_conv_flags.c\
		my_fstr/flags/number_conv_flags.c\
		my_fstr/my_fstr.c\
		my_list/create_list.c\
		my_list/handle_list.c\
		my_list/callback_list.c\
		others/my_find_in_word_array.c\
		others/my_free_word_array.c\
		others/my_free.c\

STR := $(addprefix my_str/, $(STR))
MAT := $(addprefix my_math/, $(MAT))
IO 	:= $(addprefix my_io/, $(IO))

SRC += $(STR) $(MAT) $(IO) $(DIO)
SRC := $(addprefix my/, $(SRC))

OBJ	=	$(SRC:.c=.o)

libmy.a:	$(OBJ)
	ar rc libmy.a $(OBJ)

all: libmy.a

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f libmy.a
	rm -f libdebug.a

re: fclean all

libdebug.a: CFLAGS += -g
libdebug.a: $(OBJ)
	ar rc libdebug.a $(OBJ)

debug: libdebug.a

.PHONY: all clean fclean re debug
