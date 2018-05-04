##
## EPITECH PROJECT, 2018
## Surgitoir
## File description:
## Une lib de parsing
##

CC		=		gcc -g

NAME	=		libsurgitoir.so

SRC		=		is_number.c			\
				check_number.c		\
				error.c				\
				utils.c				\
				globals.c			\
				init.c

OBJ		=		$(SRC:.c=.o)

CFLAGS	+=		-I./include -W -Wall -Wextra

all:		$(OBJ)
	$(CC) -c -fPIC $(SRC) $(CFLAGS)
	$(CC) -shared -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)

fclean:		clean
	rm -f $(NAME)
	rm -f test

re:		fclean all

test:		all
	$(CC) main.c -lm $(CFLAGS) -L./ -lsurgitoir -o test

init:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/

install: 	all init
	sudo cp $(NAME) /usr/lib/

uninstall:	fclean
	sudo rm -f /usr/lib/$(NAME)

.PHONY:		all clean fclean re test init install uninstall