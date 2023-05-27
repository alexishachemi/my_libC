##
## EPITECH PROJECT, 2023
## my_libC
## File description:
## Makefile
##

NAME	=	mylib

MNAME	=	$(NAME)_main

LNAME 	= 	lib$(NAME).a

CFLAGS 	+= -I./include/ -W -Wall -Wextra -pedantic

TFLAGS	= -lcriterion --coverage -g3

SRC		=	vfstr/my_vfstr.c\
			vfstr/flags/base_conv_flags.c\
			vfstr/flags/char_conv_flags.c\
			vfstr/flags/number_conv_flags.c\
			list/list_create.c\
			list/list_handle.c\
			str/str_alloc.c\
			str/str_alnum.c\
			str/str_case.c\
			str/str_clean.c\
			str/str_contains.c\
			str/str_copy.c\
			str/str_count.c\
			str/str_double.c\
			str/str_extract.c\
			str/str_find.c\
			str/str_fix.c\
			str/str_format.c\
			str/str_handle.c\
			str/str_merge.c\
			str/str_nb.c\
			str/str_replace.c\
			warr/warr_alloc.c\
			warr/warr_handle.c\
			warr/warr_from_str.c\
			warr/warr_to_str.c\
			math/math_compute.c\
			math/math_prime.c\
			io/io_printf.c\
			io/io_putc.c\
			io/io_putnb.c\

TSRC	=	$(subst .c,_test.c,$(SRC))

TSRC 	:= $(addprefix tests/unit_tests/, $(TSRC))

SRC 	:= $(addprefix src/, $(SRC))

OBJ		=	$(SRC:.c=.o)

TOBJ	=	$(TSRC:.c=.o)

$(LNAME):	$(OBJ)
	ar rc $(LNAME) $(OBJ)

all: $(LNAME)

clean:	tests_clean
	rm -f $(OBJ)
	rm -f $(LNAME)
	rm -f $(DNAME)

fclean: clean
	rm -f $(MNAME)

re: clean all

unit_tests: $(OBJ) $(TOBJ)
	gcc -o unit_tests $(OBJ) $(TOBJ) $(TFLAGS)

tests_run: unit_tests
	./unit_tests

tests_clean:
	rm -f $(TOBJ)
	rm -f unit_tests
	rm -f *.gc*

main: CFLAGS += -g3
main: fclean $(OBJ)
	gcc -o $(MNAME) $(OBJ) tests/main.c $(CFLAGS)

$(DNAME): CFLAGS += -g3
$(DNAME): $(OBJ)
	ar rc $(DNAME) $(OBJ)
debug: $(DNAME)

val_test: unit_tests
	valgrind --leak-check=full ./unit_tests

.PHONY: all clean fclean re debug tests_run tests_clean
