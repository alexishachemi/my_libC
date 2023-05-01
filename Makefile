##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## makefile
##

NAME	=	a.out

# Main

MAIN	=	src/main.c

TMAIN	=	tests/test_main.c

# Sources

SRC	=

TSRC	=

SRC	:= $(addprefix src/, $(SRC))

TSRC	:=	$(addprefix tests/unit_tests/, $(TSRC))

# Objects

MAIN_OBJ	=	$(MAIN:.c=.o)

TMAIN_OBJ	=	$(TEST_MAIN:.c=.o)

OBJ	=	$(SRC:.c=.o)

TOBJ	=	$(TSRC:.c=.o)

# Flags

CFLAGS	=	-W -Wall -Wextra -pedantic -I./include/

LDFLAGS	=	-L./lib/ -lmy

TFLAGS	=	-lcriterion --coverage

# Rules

$(NAME): $(MAIN_OBJ) $(OBJ) lib/libmy.a
	gcc -o $(NAME) $(MAIN_OBJ) $(OBJ) $(LDFLAGS)

all:	$(NAME)

lib/libmy.a:
	make -C lib/

clean:
	rm -f $(OBJ)
	make tests_clean
	make clean -C lib/

fclean:	clean
	make fclean -C lib/
	rm -f unit_tests
	rm -f debug_$(NAME)
	rm -f $(NAME)

re:	fclean all

unit_tests: $(OBJ) $(TOBJ) lib/libmy.a
	gcc -o unit_tests $(OBJ) $(TOBJ) $(LDFLAGS) $(TFLAGS)

tests_run: unit_tests
	./unit_tests --verbose

tests_clean:
	rm -f $(TOBJ)
	rm -f *.gcda
	rm -f *.gcno

test: $(TMAIN_OBJ) $(OBJ) lib/libmy.a
	gcc -o $(NAME) $(TMAIN_OBJ) $(OBJ) $(LDFLAGS)

lib/libdebug.a:
	make debug -C lib/

debug: CFLAGS += -g
debug: LDFLAGS := $(subst -lmy,-ldebug,$(LDFLAGS))
debug:	lib/libdebug.a $(OBJ) $(MAIN_OBJ)
	gcc -o debug_$(NAME) $(OBJ) $(MAIN_OBJ) $(LDFLAGS)

.PHONY: all clean fclean re debug
