/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_1_fill_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:07:58 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 14:11:46 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static size_t	get_len(char **args, int arg_am, int opcode, size_t arg_len[3])
{
	size_t	len;
	int		i;

	i = 0;
	len = g_optab[opcode - 1].acb == 1 ? 2 : 1;
	while (i < arg_am)
	{
		if (args[i][0] == 'r')
			arg_len[i] = 1;
		else if (args[i][0] == '%')
		{
			arg_len[i] = 4;
			if (g_optab[opcode - 1].dir_halved == 1)
				arg_len[i] /= 2;
		}
		else if (ft_isdigit(args[i][0]) || args[i][0] == '-'\
		|| args[i][0] == ':')
			arg_len[i] = 2;
		len += arg_len[i];
		i++;
	}
	return (len);
}

static char		**reset_args(char **args, size_t arg_len[3])
{
	int i;

	i = -1;
	if (args == NULL)
	{
		if (!(args = (char**)ft_memalloc(sizeof(char**) * 3)))
			return (NULL);
	}
	else
		while (++i < 3)
		{
			if (args[i])
				ft_strdel(&args[i]);
			arg_len[i] = 0;
		}
	return (args);
}

static int		check_arg(int opcode, int arg_num, char arg_t)
{
	if (g_optab[opcode - 1].type[arg_num] == 1 && arg_t == 'r')
		return (1);
	else if (g_optab[opcode - 1].type[arg_num] == 2 && arg_t == '%')
		return (1);
	else if (g_optab[opcode - 1].type[arg_num] == 3 && (arg_t == 'r'\
	|| arg_t == '%'))
		return (1);
	else if (g_optab[opcode - 1].type[arg_num] == 5 && (arg_t == 'r'\
	|| arg_t == ':' || ft_isdigit(arg_t) || arg_t == '-'))
		return (1);
	else if (g_optab[opcode - 1].type[arg_num] == 6 && (arg_t == ':'\
	|| ft_isdigit(arg_t) || arg_t == '-' || arg_t == '%'))
		return (1);
	else if (g_optab[opcode - 1].type[arg_num] == 7 && (arg_t == 'r'\
	|| arg_t == '%' || arg_t == ':' || ft_isdigit(arg_t) || arg_t == '-'))
		return (1);
	return (-1);
}

static int		check_arg_types(int opcode, int arg_am, char **args)
{
	int i;
	int j;

	i = -1;
	while (++i < arg_am)
	{
		j = 0;
		while (ft_iswhitespace(args[i][j]))
			j++;
		if (check_arg(opcode, i, args[i][j]) == -1)
			return (-1);
	}
	return (1);
}

void			fill_input(t_all *all, char *line, t_input *i)
{
	if (!(i->args = reset_args(i->args, i->arg_len)))
		error_message("Malloc error\n", all, NULL);
	if ((i->opcode = get_opcode(line)) == -1)
		error_message("Invalid instruction\n", all, NULL);
	i->acb = get_acb(all, line, &i->arg_am, i->opcode);
	if (!(i->args = fill_args(i->args, line, i->arg_am)))
		error_message("", all, NULL);
	if (check_arg_types(i->opcode, i->arg_am, i->args) == -1)
		error_message("Invalid parameter type\n", all, NULL);
	i->len = get_len(i->args, i->arg_am, i->opcode, i->arg_len);
}
