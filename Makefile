##
## EPITECH PROJECT, 2019
## cpp_rush3_2019
## File description:
## automated desc ftw
##

SRC = \
	  ./malloc.c \
	  ./free.c \
	  ./find_free.c \
	  ./helpers.c

DFLAGS = \
		 -fsanitize=address \
		 -fsanitize=alignment \
		 -fsanitize=enum \
		 -fsanitize=undefined \
		 -fsanitize=nullability

NAME = libmy_malloc.so
LDFLAGS = -shared
CPL = gcc
CFLAGS = -Wextra -Wall -I. -fPIC
DFLAGS = -Wextra -Wall -I. -fPIC -g

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CPL) -o $(NAME) $(OBJ) $(LDFLAGS)

debug: $(SRC)
	$(CPL) -o $(NAME) $(SRC) $(DFLAGS) $(LDFLAGS)

clean:
	$(foreach var, $(OBJ), if [ -e $(var) ] ; then rm -f $(var) ; fi;)
	rm -f vgcore.*

fclean: clean
	rm -f $(NAME)

re:
	$(MAKE) fclean
	$(MAKE) all

%.o: %.c
	$(CPL) $(CFLAGS) -o $@ -c $<

.PHONY: all clean fclean re
