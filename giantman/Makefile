##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## compile
##

CC = gcc

NAME	=	giantman

SRC	=	main.c		\
		file.c 		\
		tab.c 		\
		tree.c 		\
		decode.c 	\
		decompress.c\

OBJ	=	$(SRC:.c=.o)

I = -I. my.h

all:	$(NAME)

$(NAME): $(OBJ)
	$(CC) -o $(NAME) $(I) $(SRC)

clean:
	rm -f $(NAME)
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f $(OBJ)

re:	fclean all