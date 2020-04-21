# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/07/10 15:24:03 by fabbenbr          #+#    #+#              #
#    Updated: 2019/10/03 11:11:47 by grde-lau         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = filler

CC = gcc
CFLAGS = -Wall -Wextra -Werror
INCLUDES = 	includes/
FRAMEW = -framework OpenGL -framework AppKit


SRC_PATH = srcs/
SRC = 			main.o \
				init_input.o \
				map.o \
				replay_array.o \
				replay_saver.o \
				reader_funcs.o \
				param_parser.o \
				free.o \
				ui.o \
				ui2.o \
				ui3.o \
				ui4.o \
				ui_score.o \
				key.o \
				update_map.o \
				update_piece.o \
				init_window.o \
				loop.o \
				opti_token.o \

OBJ = 			$(addprefix $(SRC_PATH), $(SRC)) \

MLX_PATH = 	minilibx_macos/
MLX =			libmlx.a

LFT_PATH = 	../Libft/
LFT =			CompleteLibft.a

LIB =			$(addprefix $(MLX_PATH), $(MLX)) \
				$(addprefix $(LFT_PATH), $(LFT))

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
	@$(CC) -o $@ $^ -I $(INCLUDES) $(CFLAGS) $(FRAMEW)
	@echo "$(PURPLE_E)$(NAME)\t\tcompile$(END_E)"

all: $(NAME)

%.a:
	@$(MAKE) -C $(@D)/

%.o:        %.c
	@$(CC) -c -o $@ $< -I $(INCLUDES) $(CFLAGS)

clean:
	@$(MAKE) clean -C $(LFT_PATH)
	@$(MAKE) clean -C minilibx_macos/
	@rm -f $(OBJ)
	@echo "$(PURPLE_E)$(NAME)\t\tclean$(END_E)"

fclean:
	@$(MAKE) fclean -C $(LFT_PATH)
	@echo "$(PURPLE_E)$(NAME)\t\tfclean$(END_E)"
	@rm -f $(OBJ) $(NAME)

re: fclean all

.PHONY: clean fclean all re lib
