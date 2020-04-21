# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/05/16 13:02:11 by fabbenbr          #+#    #+#              #
#    Updated: 2019/05/16 13:02:12 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			./../libftgnl.a

CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror

INCLUDES = 		-I ./includes/get_next_line.h \
				-I ./../libft/includes/

SRC_MEM = 		../Libft/srcs/mem/
SRC_STR = 		../Libft/srcs/str/
SRC_GNL =		./srcs/

SRC_M =		ft_memset.o

SRC_S =			ft_strnew.o \
				ft_strjoin.o \
				ft_strdel.o \
				ft_strdel_neg.o \
				ft_strchr.o \
				ft_strsub.o \
				ft_strdup.o \
				ft_strlen.o \
				ft_strcat.o \

SRC_G =			get_next_line.o \

OBJ_MEM = 		$(addprefix $(SRC_MEM), $(SRC_M))
OBJ_STR = 		$(addprefix $(SRC_STR), $(SRC_S))
OBJ_GNL =			$(addprefix $(SRC_GNL), $(SRC_G))

OBJ_ALL = 		$(OBJ_STR) $(OBJ_GNL) $(OBJ_MEM)

END_E       = 	\033[00m
RED_E       = 	\033[01;31m
GREEN_E     = 	\033[01;32m
YELLOW_E    = 	\033[01;33m
PURPLE_E    = 	\033[01;35m
CYAN_E      = 	\033[01;36m
WHITE_E     = 	\033[01;37m
BOLD_E      = 	\033[1m
UNDERLINE_E = 	\033[4m

all: $(NAME)

$(NAME): $(OBJ_ALL)
		@ar -rcs $@ $^
		@echo "$(GREEN_E)$(NAME)\tCompiled$(END_E)"
		ranlib $(NAME)

%.o: %.c
		@echo "$(YELLOW_E)Compiling $@$(END_E)"
		@$(CC) -c -o $@ $< $(INCLUDES) $(CFLAGS)

clean:
		@rm -f $(OBJ_ALL)
		@echo "$(YELLOW_E)$(NAME)\tclean$(END_E)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED_E)$(NAME)\tfclean$(END_E)"

re: fclean all

.PHONY: clean fclean all re
