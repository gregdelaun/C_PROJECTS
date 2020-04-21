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

NAME = 			CompleteLibft.a

CC = 			gcc
CFLAGS = 		-Wall -Wextra -Werror

INCLUDES = 		-I ./libft/includes/ \
				-I ./get_next_line/includes/ \
				-I ./libft/ft_printf/inludes/

SRC_CHAR = 		./libft/srcs/char/
SRC_INT = 		./libft/srcs/int/
SRC_IS = 		./libft/srcs/is/
SRC_MEM = 		./libft/srcs/mem/
SRC_PUT = 		./libft/srcs/put/
SRC_LST =		./libft/srcs/lst/
SRC_STR = 		./libft/srcs/str/
SRC_OTHER = 	./libft/srcs/other/
SRC_PRINTF =	./ft_printf/srcs/
SRC_GNL =		./get_next_line/srcs/

SRC_C = 		ft_charcat.o \
				ft_chararrclr.o \
				pt_charput_c_rot.o \
				ft_charswap.o \
				ft_chartoupper.o \
				ft_chararrprint.o \

SRC_IN = 		ft_intarrclr.o \
				ft_conn_amount.o \
				ft_intarrprint.o \
				ft_intmakepos.o \
				ft_inttopower.o \
				ft_intarr.o \
				ft_setintarr.o \
				ft_copyintarr.o \
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

SRC_I = 		ft_isalnum.o \
				ft_isalpha.o \
				ft_isascii.o \
				ft_isdigit.o \
				ft_iseven.o \
				ft_ishexa.o \
				ft_isprint.o \
				ft_isprintfflag.o \
				ft_iswhitespace.o \
				ft_isinstr.o \

SRC_M =			ft_memalloc.o \
				ft_memccpy.o \
				ft_memchr.o \
				ft_memcmp.o \
				ft_memcpy.o \
				ft_memdel.o \
				ft_memdell.o \
				ft_memmove.o \
				ft_memset.o \

SRC_P = 		ft_putchar_fd.o \
				ft_putchar.o \
				ft_putendl_fd.o \
				ft_putendl.o \
				ft_putnbr_fd.o \
				ft_putnbr.o \
				ft_putstr_fd_c0.o \
				ft_putstr_fd.o \
				ft_putstr.o \

SRC_L =			ft_lstadd.o \
				ft_lstdel.o \
				ft_lstdelone.o \
				ft_lstiter.o \
				ft_lstmap.o \
				ft_lstnew.o \

SRC_S = 		ft_strcat.o \
				ft_strcatn.o \
				ft_strchr.o \
				ft_strclr.o \
				ft_strcmp.o \
				ft_strcpy.o \
				ft_strdel_neg.o \
				ft_strdel.o \
				ft_strdell.o \
				ft_strdup.o \
				ft_strequ.o \
				ft_striter.o \
				ft_striteri.o \
				ft_strjoin.o \
				ft_strjoinn.o \
				ft_strjoinspace.o \
				ft_strlcat.o \
				ft_strlen_c.o \
				ft_strlen_c0.o \
				ft_strlen.o \
				ft_strmap.o \
				ft_strmapi.o \
				ft_strncat_c0.o \
				ft_strncat.o \
				ft_strncmp.o \
				ft_strncpy.o \
				ft_strnequ.o \
				ft_strnew.o \
				ft_strnstr.o \
				ft_strrchr.o \
				ft_strrevcpy.o \
				ft_strsplit.o \
				ft_strstr.o \
				ft_strsub.o \
				ft_strtoupper.o \
				ft_strtrim.o \
				pt_strmove.o \
				pt_strrot.o \
				ft_strccpy.o \
				ft_strclen.o \
				ft_strnewncpy.o \

SRC_O = 		ft_atoi.o \
				ft_atoi_uint.o \
				ft_natoi.o \
				ft_binlen_u.o \
				ft_binlen.o \
				ft_bzero.o \
				ft_divlen_ul.o \
				ft_divlen.o \
				ft_hexaconverter.o \
				ft_hexavalue.o \
				ft_itoa.o \
				ft_reversebin.o \
				ft_scinot_l.o \
				ft_scinot.o \
				ft_tolower.o \
				pt_bintohex.o \
				pt_dectobin_l.o \
				pt_dectobin.o \
				pt_ftoa_long.o \
				pt_ftoa.o \
				pt_itoa.o \
				pt_itoa_j.o \
				pt_itoa_ll.o \
				pt_itoa_l.o \
				pt_itoa_z.o \
				pt_itoa_h.o \
				pt_itoa_hh.o \
				pt_itoa_uint.o \
				pt_itoa_uint_l.o \
				pt_itoa_uint_ll.o \
				pt_itoa_uint_h.o \
				pt_itoa_uint_hh.o \
				pt_itoa_uint_z.o \
				pt_itoa_uint_j.o \
				pt_pointeraddress.o \
				ft_arrclr.o \
				ft_atof.o \
				ft_hexaconverter_old.o \
				ft_n0.o \
				ft_random.o \
				ft_toupper.o \
				ft_find_c.o \


SRC_G =			get_next_line.o \

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
OBJ_GNL =		$(addprefix $(SRC_GNL), $(SRC_G))
OBJ_LST =		$(addprefix $(SRC_LST), $(SRC_L))

OBJ_ALL = 		$(OBJ_CHAR) $(OBJ_INT) $(OBJ_IS) \
				$(OBJ_MEM) $(OBJ_PUT) $(OBJ_STR) \
				$(OBJ_OTHER) $(OBJ_PR) $(OBJ_GNL) \
				$(OBJ_LST)

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

lft:
		@$(MAKE) -C libft/

lftclean:
		@$(MAKE) clean -C libft/

lftfclean:
		@$(MAKE) fclean -C libft/

lftre:
		@$(MAKE) re -C libft/

pf:
		@$(MAKE) -C ft_printf/

pfclean:
		@$(MAKE) clean -C ft_printf/

pffclean:
		@$(MAKE) fclean -C ft_printf/

pfre:
		@$(MAKE) re -C ft_printf/

gnl:
		@$(MAKE) -C get_next_line/

gnlclean:
		@$(MAKE) clean -C get_next_line/

gnlfclean:
		@$(MAKE) fclean -C get_next_line/

gnlre:
		@$(MAKE) re -C get_next_line/

alllib:
		@$(MAKE) -C libft/
		@$(MAKE) -C ft_printf/
		@$(MAKE) -C get_next_line/
clean:
		@rm -f $(OBJ_ALL)
		@echo "$(YELLOW_E)$(NAME)\tclean$(END_E)"
		@echo "$(RED_E)All .o have been successfully removed.$(END_E)"

fclean: clean
		@rm -f $(NAME)
		@echo "$(RED_E)$(NAME)\tfclean$(END_E)"
		@echo "$(RED_E)All .o files and libraries have been successfully removed.$(END_E)"

re: fclean all

.PHONY: clean fclean all re
