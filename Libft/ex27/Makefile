NAME = ft_display_file
SRC = *.c
OBJ = *.o
CC = gcc
FLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME):
	$(CC) -c $(FLAGS) $(SRC)
	$(CC) -o $(NAME) $(FLAGS) $(OBJ)
clean:
	/bin/rm -f $(OBJ)
fclean: clean
	/bin/rm -f $(NAME)
re: fclean all