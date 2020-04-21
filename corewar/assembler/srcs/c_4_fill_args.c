/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_4_fill_args.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:38:42 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/24 15:38:43 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	get_pos(char *line, int *k, int *j, int *i)
{
	*k = -1;
	*j = 0;
	while (ft_isalpha(line[*j]) || line[*j] == '_' || line[*j] == ':')
		(*j)++;
	while (ft_iswhitespace(line[*j]))
		(*j)++;
	*i = *j;
}

static int	arg_check(char *arg)
{
	int		i;

	i = 0;
	while (ft_iswhitespace(arg[i]))
		i++;
	if (arg[i] == '%')
		return (check_direct(arg, i));
	else if (arg[i] == 'r')
		return (check_reg(arg, i));
	else if (ft_isdigit(arg[i]) || arg[i] == '-')
		return (check_indirect(arg, i));
	else if (arg[i] == ':')
		return (1);
	return (0);
}

static char	**return_clear(char **args, int k)
{
	while (--k >= 0)
		ft_strdel(&args[k]);
	return (NULL);
}

char		**fill_args(char **args, char *line, int arg_am)
{
	int i;
	int j;
	int k;

	get_pos(line, &k, &j, &i);
	while (++k < arg_am)
	{
		if (k != 0)
			j = i;
		while (ft_iswhitespace(line[j]))
			j++;
		while (line[i] != ',' && line[i] != '\0')
			i++;
		if (!(args[k] = ft_strnew(i - j)))
			return (return_clear(args, k));
		args[k] = ft_strncpy(args[k], &line[j], i - j);
		if (arg_check(args[k]) == 0)
		{
			syntax_error("Syntax error at token [TOKEN] INSTRUCTION ", args[k]);
			return (return_clear(args, k));
		}
		i++;
	}
	return (args);
}
