/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:46:02 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 21:46:52 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_lt	check_format_board(t_lt args, char *line)
{
	args.y_board = ft_atoi(ft_strchr(line, ' '));
	args.x_board = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	return (args);
}

t_lt	put_numbers_in_tab_for_big_x(t_lt args)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (args.tab[i])
	{
		j = 0;
		while (args.tab[i][j])
		{
			if (args.tab[i][j] == '.')
				args.tab[i][j] = '0';
			if (args.tab[i][j] == 'X' || args.tab[i][j] == 'x')
				args.tab[i][j] = '2';
			j++;
		}
		i++;
	}
	return (args);
}

t_lt	put_numbers_in_tab(t_lt args)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (args.tab[i])
	{
		j = 0;
		while (args.tab[i][j])
		{
			if (args.tab[i][j] == '.')
				args.tab[i][j] = '0';
			if (args.tab[i][j] == 'O' || args.tab[i][j] == 'o')
				args.tab[i][j] = '2';
			j++;
		}
		i++;
	}
	return (args);
}

int		check_token(t_lt *args, char *line)
{
	(*args).y_token = ft_atoi(ft_strchr(line, ' '));
	(*args).x_token = ft_atoi(ft_strchr(ft_strchr(line, ' ') + 1, ' '));
	if (!((*args).tok = malloc(sizeof(char*) * ((*args).y_token + 1))))
		exit(0);
	args->j = (*args).y_token;
	while (args->j--)
	{
		ft_get_next_line(0, &line);
		(*args).tok[args->i++] = line;
	}
	(*args).tok[args->i] = NULL;
	args->i = -1;
	while ((*args).tok[++args->i])
	{
		args->j = -1;
		while ((*args).tok[args->i][++args->j])
		{
			if ((*args).tok[args->i][args->j] == '*')
				(*args).tok[args->i][args->j] = '1';
			else
				(*args).tok[args->i][args->j] = '0';
		}
	}
	return (1);
}

int		several_lenght_checks(t_lt *args, char *line, int ret)
{
	int i;

	ret = 0;
	args->mapjoin = "\0";
	while ((ret = ft_get_next_line(0, &line)) == 1)
	{
		if (line[0] == 'P' && line[1] == 'l' && line[2] == 'a')
			*args = check_format_board((*args), line);
		if (line[4] == '0')
		{
			args->good = 1;
			free(line);
			break ;
		}
		free(line);
	}
	i = (*args).y_board;
	return (ret);
}
