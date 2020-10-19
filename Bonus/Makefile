##
## EPITECH PROJECT, 2019
## PSU_my_sokoban_2019
## File description:
## Makefile
##

#flag#

CFLAGS = -Wall -Wextra -Werror -Wshadow

CPPFLAGS = -iquote $(IDIR)

DBGFLAGS = -g3 -ggdb

CMPFLAGS = -o

LDFLAGS = -lncurses -lcsfml-audio -lcsfml-system

LIBFLAGS = -L lib/ -lmy

#source#

SRC = $(wildcard ./src/*.c)

OBJ = $(SRC:.c=.o)

NAME = my_sokoban

IDIR = ./include

CC = clang

#rules#

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C lib/my
	$(CC) $(CMPFLAGS) $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBFLAGS)
	rm -f $(OBJ)

debug: CFLAGS += $(DBGFLAGS)
debug: $(NAME)

clean:
	rm -f $(OBJ)
	rm -f include/*.gc*

fclean: clean
	rm -f $(NAME)
	rm -f a.out
	rm -f vgcore*

re: fclean all

lib:
	make -C lib/my

ex: $(OBJ)
	$(CC) $(CMPFLAGS) $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBFLAGS)
	rm -f $(OBJ)

mclean: fclean
	rm -f lib/libmy.a

.PHONY: fclean clean re all debug lib mclean ex

csfml:
	$(CC) $(CMPFLAGS) $(NAME) $(OBJ) $(CFLAGS) $(CPPFLAGS) $(LDFLAGS) $(LIBFLAGS) -lcsfml-audio -lcsfml-system

tests_run: LDFLAGS += -lcriterion --coverage

tests_run:
		$(CC) -o unit_tests tests/project.c $(CPPFLAGS) $(LDFLAGS) $(CFLAGS)
		./unit_tests
		gcovr -e tests/
