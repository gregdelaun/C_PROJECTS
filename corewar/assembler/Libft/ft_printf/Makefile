# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/10/13 14:22:54 by fabbenbr          #+#    #+#              #
#    Updated: 2018/10/15 10:45:52 by fabbenbr         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 			./../libftprintf.a

CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror

INCLUDES = 		-I ./includes/ \
				-I ./../libft/includes/

SRC_CHAR = 		./../libft/srcs/char/
SRC_INT = 		./../libft/srcs/int/
SRC_IS = 		./../libft/srcs/is/
SRC_MEM = 		./../libft/srcs/mem/
SRC_PUT = 		./../libft/srcs/put/
SRC_STR = 		./../libft/srcs/str/
SRC_OTHER = 	./../libft/srcs/other/
SRC_PRINTF =	./srcs/

SRC_C = 		ft_charcat.o \
				pt_charput_c_rot.o \
				ft_charswap.o \
				ft_chartoupper.o \

SRC_IN = 		ft_intmakepos.o \
				ft_inttopower.o \
				pt_inttohexastr.o \
				pt_inttohexastr_h.o \
				pt_inttohexastr_hh.o \
				pt_inttohexastr_l.o \
				pt_inttohexastr_ll.o \
				pt_inttohexastr_z.o \
				pt_inttohexastr_j.o \
				pt_intoctal.o \
				pt_intoctal_h.o \
				pt_intoctal_hh.o \
				pt_intoctal_l.o \
				pt_intoctal_ll.o \
				pt_intoctal_z.o \
				pt_intoctal_j.o \

SRC_I = 		ft_isdigit.o \
				ft_isprintfflag.o \
				ft_iseven.o

SRC_M =			ft_memdell.o \
				ft_memalloc.o \
				ft_memset.o \
				ft_memmove.o \
				ft_memcpy.o \

SRC_P = 		ft_putstr_fd_c0.o \
				ft_putchar_fd.o \

SRC_S = 		ft_strnew.o \
				ft_strcpy.o \
				ft_strdel.o \
				ft_strlen.o \
				ft_strlen_c.o \
				ft_strlen_c0.o \
				ft_strcat.o \
				ft_strncat.o \
				ft_strncat_c0.o \
				ft_strrevcpy.o \
				ft_strncpy.o \
				ft_strclr.o \
				pt_strrot.o \
				ft_strtoupper.o \
				pt_strmove.o \
				ft_strcmp.o \

SRC_O = 		ft_atoi.o \
				pt_dectobin.o \
				pt_itoa.o \
				pt_itoa_j.o \
				pt_itoa_ll.o \
				pt_itoa_l.o \
				pt_itoa_z.o \
				pt_itoa_h.o \
				pt_itoa_hh.o \
				ft_scinot.o \
				ft_scinot_l.o \
				ft_divlen.o \
				pt_ftoa.o \
				pt_ftoa_long.o \
				ft_binlen.o \
				ft_reversebin.o \
				pt_itoa_uint.o \
				pt_itoa_uint_l.o \
				pt_itoa_uint_ll.o \
				pt_itoa_uint_h.o \
				pt_itoa_uint_hh.o \
				pt_itoa_uint_z.o \
				pt_itoa_uint_j.o \
				pt_pointeraddress.o \
				ft_divlen.o \
				ft_divlen_ul.o \
				ft_hexavalue.o \
				pt_dectobin.o \
				pt_dectobin_l.o \
				ft_binlen_u.o \
				pt_bintohex.o \

SRC_PR = 		ft_printf.o \
				struct.o \
				precision.o \
				input_prep.o \
				width.o \
				n_out.o \
				flags/b.o \
				flags/c.o \
				flags/d.o \
				flags/e.o \
				flags/f.o \
				flags/g.o \
				flags/n.o \
				flags/o.o \
				flags/p.o \
				flags/s.o \
				flags/u.o \
				flags/x.o \
				flags/perc.o \
				flags/t.o \

OBJ_CHAR = 		$(addprefix $(SRC_CHAR), $(SRC_C))
OBJ_INT = 		$(addprefix $(SRC_INT), $(SRC_IN))
OBJ_IS = 		$(addprefix $(SRC_IS), $(SRC_I))
OBJ_MEM = 		$(addprefix $(SRC_MEM), $(SRC_M))
OBJ_PUT = 		$(addprefix $(SRC_PUT), $(SRC_P))
OBJ_STR = 		$(addprefix $(SRC_STR), $(SRC_S))
OBJ_OTHER =		$(addprefix $(SRC_OTHER), $(SRC_O))
OBJ_PR = 		$(addprefix $(SRC_PRINTF), $(SRC_PR))
OBJ_PR_F =		$(addprefix $(SRC_PRINTF_F), $(SRC_PR_F))

OBJ_ALL = 		$(OBJ_CHAR) $(OBJ_INT) $(OBJ_IS) \
				$(OBJ_MEM) $(OBJ_PUT) $(OBJ_STR) $(OBJ_OTHER) $(OBJ_PR)

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
