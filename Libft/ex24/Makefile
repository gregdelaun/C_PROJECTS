NAME = libft.a

CC = gcc

INCLUDES = ./includes

FLAGS = -Wall -Wextra -Werror

SRC = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c \
			srcs/ft_strlen.c srcs/ft_swap.c

OBJ = ft_putchar.o ft_putstr.o ft_strcmp.o \
			ft_strlen.o ft_swap.o

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC) -I $(INCLUDES)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all