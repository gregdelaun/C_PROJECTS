/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:51:41 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 14:51:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# define REG	"01"
# define DIR	"10"
# define IND	"11"

# include <fcntl.h>
# include <stdio.h>
# include "../Libft/Libft/includes/libft.h"
# include "../Libft/get_next_line/includes/get_next_line.h"
# include "../Libft/ft_printf/includes/ft_printf.h"
# include "op.h"

typedef struct		s_input
{
	int				opcode;
	int				acb;
	int				arg_am;
	size_t			len;
	size_t			arg_len[3];
	char			**args;
}					t_input;

typedef struct		s_label
{
	char			*name;
	char			*line;
	int				pos;
	struct s_label	*next;
}					t_label;

typedef struct		s_all
{
	int				champ_name;
	int				champ_comm;
	t_header		h;
	t_input			i;
	t_label			*l;
	char			*file;
	size_t			templen;
	size_t			len;
	char			*result;
}					t_all;

/*
**	input reading and organization
*/
void				reader(t_all *all, int fd);
void				get_name_comment(t_all *all, char *line, int type);
void				name_comment_check(t_all *all, int q, int t);
void				check_for_label(t_all *all, char *line, int fd, size_t *i);
t_label				*add_label(t_label *list, char *line, int t);
void				add_line(t_all *all, char *line, size_t i);
void				reverse_list(t_all *all);
/*
**	input processing
*/
int					get_opcode(char *line);
void				fill_input(t_all *all, char *line, t_input *i);
char				*get_result(t_all *all);
int					get_acb(t_all *all, char *line, int *arg_am, int opcode);
char				**fill_args(char **args, char *line, int arg_am);
char				*realloc_result(char *res, t_all *all, int i);
size_t				ft_strlen_alnum(char *line);
int					check_arg_am(int arg_am, int opcode);
int					check_direct(char *arg, int i);
int					check_indirect(char *arg, int i);
int					check_reg(char *arg, int i);
/*
**	output
*/
void				create_file(t_all *all);
/*
**	error and free
*/
void				free_args(char ***args);
void				free_labels(t_label **list);
void				clean_up(t_all *all, char *line);
void				syntax_error(char *line, char *info);
void				error_message(char *error, t_all *all, char *line);
#endif
