C = clang

NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

LIBFT = Libft

DIR_S = sources

DIR_O = temporary

HEADER = include

SOURCES =	ft_printf.c\
			ft_puts.c\
 	  		ft_d.c\
 	  		ft_d2.c\
	  		ft_u.c\
			ft_o.c\
			ft_x.c\
			ft_s.c\
			pourcent.c\
			ft_c.c\
			ft_p.c\
			ft_f.c\
			ft_f2.c\
			ft_o2.c\
			ft_puts2.c\
			ft_puts3.c\

SRCS = $(addprefix $(DIR_S)/,$(SOURCES))

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	@make -C $(LIBFT)
	@cp libft/libft.a ./$(NAME)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

$(DIR_O)/%.o: $(DIR_S)/%.c
	@mkdir -p temporary
	@$(CC) $(FLAGS) -I $(HEADER) -o $@ -c $<

clean:
	@rm -f $(OBJS)
	@rm -rf $(DIR_O)
	@make clean -C $(LIBFT)

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT)

re: fclean all
