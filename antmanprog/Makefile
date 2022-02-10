##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

CC = gcc

NAME	=	antman

SRC	=	main.c		\
		file.c 		\
		tab.c 		\
		findpath.c 	\
		tree.c 		\
		print.c 	\
		printnext.c \
		revstr.c 	\

OBJ	=	$(SRC:.c=.o)

CFLAGS = -g1

I = -I. my.h

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(CFLAGS) $(I) $(SRC)

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all