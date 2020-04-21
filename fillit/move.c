/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:33:43 by quroba            #+#    #+#             */
/*   Updated: 2019/03/28 16:23:45 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		move_tab(t_lst *list)
{
	t_lst	*tmp;

	tmp = list;
	while (tmp)
	{
		tmp->tab = move_left(time_move_left(tmp->tab), tmp->tab);
		tmp->tab = move_up(time_move_up(tmp->tab), tmp->tab);
		tmp = tmp->next;
	}
	if (resolve(list) == 1)
		return (1);
	return (0);
}

char	**move_left(int times, char **tab)
{
	t_int	pos;

	pos.a = 0;
	while (tab[pos.a])
	{
		pos.c = times;
		pos.b = 0;
		while (tab[pos.a][pos.b])
		{
			if (tab[pos.a][pos.b] == '#' && pos.c > 0)
			{
				tab[pos.a][pos.b] = '.';
				tab[pos.a][pos.b - pos.c] = '#';
			}
			pos.b++;
		}
		pos.a++;
	}
	return (tab);
}

char	**move_up(int times, char **tab)
{
	t_int	pos;

	pos.b = 0;
	while (pos.b < 4)
	{
		pos.c = times;
		pos.a = 0;
		while (pos.a < 4)
		{
			if (tab[pos.a][pos.b] == '#' && pos.c > 0)
			{
				tab[pos.a][pos.b] = '.';
				tab[pos.a - pos.c][pos.b] = '#';
			}
			pos.a++;
		}
		pos.b++;
	}
	return (tab);
}

int		time_move_left(char **tab)
{
	t_int	pos;

	pos.b = 0;
	pos.d = 0;
	pos.e = 0;
	while (pos.b < 4)
	{
		pos.a = 0;
		pos.c = 0;
		while (pos.a < 4)
		{
			if (tab[pos.a][pos.b] == '#')
				pos.e++;
			if (pos.e == 4)
				break ;
			if (tab[pos.a][pos.b] == '.')
				pos.c++;
			pos.a++;
		}
		if (pos.c == 4)
			pos.d++;
		pos.b++;
	}
	return (pos.d);
}

int		time_move_up(char **tab)
{
	t_int	pos;

	pos.a = 0;
	pos.d = 0;
	pos.e = 0;
	while (pos.a < 4)
	{
		pos.b = 0;
		pos.c = 0;
		while (pos.b < 4)
		{
			if (tab[pos.a][pos.b] == '#')
				pos.e++;
			if (pos.e == 4)
				break ;
			if (tab[pos.a][pos.b] == '.')
				pos.c++;
			pos.b++;
		}
		if (pos.c == 4)
			pos.d++;
		pos.a++;
	}
	return (pos.d);
}
