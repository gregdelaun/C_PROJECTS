/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_two.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:04:54 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 22:05:28 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_list_two(t_lt *args)
{
	args->y_board = 0;
	args->x_board = 0;
	args->y_token = 0;
	args->x_token = 0;
	args->good = 0;
	args->savedfirst_j = 0;
	args->savedfirst_i = 0;
	args->saved_j = 0;
	args->saved_i = 0;
	args->retj = 0;
	args->reti = 0;
	args->final_x = 0;
	args->final_y = 0;
	args->score = 0;
	args->save = 0;
	args->save2 = 0;
	args->w = 0;
	args->i = 0;
	args->j = 0;
	args->p = 0;
}

int		several_lenght_checks_two(t_lt *args, char *line, int ret)
{
	args->i = (*args).y_board;
	while ((ret = ft_get_next_line(0, &line)) == 1)
	{
		if (ft_isdigit(line[0]) == 1)
		{
			args->mapjoin = ft_strjoin(args->mapjoin, &line[4]);
			args->mapjoin = ft_strjoinfree(args->mapjoin, "\n", 0);
			args->i--;
		}
		if (args->i == 0)
			break ;
	}
	while ((ret = ft_get_next_line(0, &line)) == 1)
	{
		if (line[0] == 'P' && line[1] == 'i' && line[2] == 'e')
			check_token(&(*args), line);
		break ;
	}
	(*args).tab = ft_strsplit(args->mapjoin, '\n');
	if ((*args).myplayer_id == 'O')
		(*args) = put_numbers_in_tab((*args));
	if ((*args).myplayer_id == 'X')
		(*args) = put_numbers_in_tab_for_big_x((*args));
	return (1);
}

int		check_numbers_of_two(t_lt args)
{
	int i;
	int j;
	int c;

	i = 0;
	j = 0;
	c = 0;
	while (args.tab[i])
	{
		j = 0;
		while (args.tab[i][j])
		{
			if (args.tab[i][j] == '2')
			{
				c++;
			}
			j++;
		}
		i++;
	}
	return (c);
}
