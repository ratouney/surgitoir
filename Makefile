##
## EPITECH PROJECT, 2018
## Surgitoir
## File description:
## Une lib de parsing
##

CC		=		gcc -g

NAME		=		libsurgitoir.so

SRC		=		is_number.c			\
				check_number.c			\
				check_number_range.c		\
				error.c				\
				utils.c				\
				globals.c			\
				init.c				\
				custom_number.c

OBJ		=		$(SRC:.c=.o)

CFLAGS		+=		-I./include -W -Wall -Wextra

TEST_FILE	=		main-test.c

all:		$(OBJ)
	$(CC) -c -fPIC $(SRC) $(CFLAGS)
	$(CC) -shared -o $(NAME) $(OBJ) -lm

clean:
	rm -f $(OBJ)
	rm -f *~
	rm -f include/*~

fclean:		clean
	rm -f $(NAME)
	rm -f test

re:		fclean all

test:		all
	$(CC) $(TEST_FILE) -lm $(CFLAGS) -L./ -lsurgitoir -o test
	./test

init:
	export LD_LIBRARY_PATH=$LD_LIBRARY_PATH:/usr/lib/

install: 	all init
	sudo cp $(NAME) /usr/lib/
	sudo cp include/* /usr/include/

uninstall:	fclean
	sudo rm -fv /usr/lib/$(NAME)
	sudo rm -fv /usr/include/surgitoir*

.PHONY:		all clean fclean re test init install uninstall
