##
## EPITECH PROJECT, 2022
## Makefile
## File description:
## s
##

CC	=	gcc

SRC	=	../src/maze_gen_fct.c			\
		../src/maze_gen_fct2.c			\
		../src/maze_fct.c				\
		generator.c

OBJ     = 	$(SRC:.c=.o)

TEMP	=	*.gcda *.gcno *.gch *.tmp

NAME	=	generator

LFLAGS	= 	-L ../lib/my/ -lmy -lm

CFLAGS	=	-Wall -Wextra

CPPFLAGS	=	-I ../include

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(OBJ) $(LFLAGS)

unit_tests: fclean libmy.a
	$(CC) tests/units_tests.c libmy.a -lcriterion --coverage

tests_run: unit_tests
	./a.out

clean:
	$(RM) $(OBJ)
	$(RM) $(TEMP)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY = clean fclean re all
