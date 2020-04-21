
NAME = fillit

LIB = ./libft/

FT_LIB = $(addprefix $(LIB), libft.a)

FT_LNK  = -L ./libft -lft 

SRCS = fillit.c resolve.c move.c \
	   checkerror.c create.c dimension.c

OBJ = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all clean fclean re

all : $(NAME)

$(FT_LIB) :
	make -C $(LIB)

$(NAME) : $(FT_LIB) $(OBJ)
	@gcc $(FLAGS) $(SRCS) $(FT_LNK) -o $(NAME)
	@echo "Compilation success"

clean :
	@make -C $(LIB) clean
	@rm -rf $(OBJ)
	@echo "Delete .o"

fclean : clean
	@rm -rf $(NAME)
	@make -C $(LIB) fclean
	@echo "Delete fillit"

re : fclean all
