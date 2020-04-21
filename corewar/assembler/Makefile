NAME =		asm

CC =		gcc
FLAGS =		-Wall -Wextra -Werror
INCLUDES =	includes/

SRC_PATH =	srcs/
SRC =		a_0_main.o \
			b_0_reader.o \
			b_1_name_comment.o \
			b_2_name_comment_2.o \
			b_3_add_label.o \
			c_0_create_result.o \
			c_1_fill_input.o \
			c_2_opcode.o \
			c_3_acb.o \
			c_4_fill_args.o \
			c_5_errorchecking.o \
			d_0_file_creator.o \
			e_0_error_message.o \
			e_dump.o \
			op.o \

OBJ =		$(addprefix $(SRC_PATH), $(SRC))

LFT_PATH =	Libft/
LFT =		CompleteLibft.a

LIB =		$(addprefix $(LFT_PATH), $(LFT))

END_E       = \033[00m
RED_E       = \033[01;31m
GREEN_E     = \033[01;32m
YELLOW_E    = \033[01;33m
PURPLE_E    = \033[01;35m
CYAN_E      = \033[01;36m
WHITE_E     = \033[01;37m
BOLD_E      = \033[1m
UNDERLINE_E = \033[4m

$(NAME): $(OBJ) $(LIB)
	@$(CC) -o $@ $^ -I $(INCLUDES) #$(FLAGS)
	@echo "$(PURPLE_E)$(NAME)\t\tcompile$(END_E)"

all: $(NAME)

%.a:
	@$(MAKE) -C $(@D)/

%.o:        %.c
	@$(CC) -c -o $@ $< -I $(INCLUDES) #$(FLAGS)

clean:
	@$(MAKE) clean -C $(LFT_PATH)
	@rm -f $(OBJ)
	@echo "$(PURPLE_E)$(NAME)\t\tclean$(END_E)"

fclean:
	@$(MAKE) fclean -C $(LFT_PATH)
	@echo "$(PURPLE_E)$(NAME)\t\tfclean$(END_E)"
	@rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re lib
