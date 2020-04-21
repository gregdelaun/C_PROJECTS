/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:28:51 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 21:38:17 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_lt	create_heat_map(t_lt args)
{
	args.i = 0;
	if (!(args.heat = malloc(sizeof(args.heat) * args.y_board + 1)))
		exit(0);
	args.heat[args.y_board] = NULL;
	args.i = 0;
	while (args.i != args.y_board)
		if (!(args.heat[args.i++] = malloc(sizeof(int) * (args.x_board + 1))))
			exit(0);
	args.i = -1;
	while (args.tab[++args.i])
	{
		args.j = -1;
		while (args.tab[args.i][++args.j])
		{
			if (args.tab[args.i][args.j] == args.nmi_id)
				args.heat[args.i][args.j] = -1;
			else if (args.tab[args.i][args.j] == args.myplayer_id)
				args.heat[args.i][args.j] = -2;
			else if (args.tab[args.i][args.j] == '.')
				args.heat[args.i][args.j] = 0;
			else
				args.heat[args.i][args.j] = 0;
		}
	}
	return (args);
}

t_lt	init_the_heat2(t_lt args, int x, int y)
{
	if (x + 1 < args.x_board && args.heat[y][x + 1] == -1)
		args.heat[y][x] = 1;
	if (y + 1 < args.y_board && args.heat[y + 1][x] == -1)
		args.heat[y][x] = 1;
	if (x + 1 < args.x_board && y + 1 < args.y_board &&
			args.heat[y + 1][x + 1] == -1)
		args.heat[y][x] = 1;
	if (x + 1 < args.x_board && y - 1 >= 0 && args.heat[y - 1][x + 1] == -1)
		args.heat[y][x] = 1;
	if (x - 1 >= 0 && args.heat[y][x - 1] == -1)
		args.heat[y][x] = 1;
	if (y - 1 >= 0 && args.heat[y - 1][x] == -1)
		args.heat[y][x] = 1;
	if (x - 1 >= 0 && y - 1 >= 0 && args.heat[y - 1][x - 1] == -1)
		args.heat[y][x] = 1;
	if (x - 1 >= 0 && y + 1 < args.y_board && args.heat[y + 1][x - 1] == -1)
		args.heat[y][x] = 1;
	return (args);
}

t_lt	init_the_heat(t_lt args)
{
	int x;
	int y;
	int i;
	int j;

	x = 0;
	y = 0;
	i = 0;
	while (y < args.y_board)
	{
		while (x < args.x_board)
		{
			if (args.heat[y][x] == 0)
				args = init_the_heat2(args, x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (args);
}

t_lt	put_numbers_in_heat_two(t_lt args, int i, int x, int y)
{
	if (x + 1 < args.x_board && args.heat[y][x + 1] == i)
		args.heat[y][x] = i + 1;
	if (y + 1 < args.y_board && args.heat[y + 1][x] == i)
		args.heat[y][x] = i + 1;
	if (x + 1 < args.x_board && y + 1 < args.y_board
			&& args.heat[y + 1][x + 1] == i)
		args.heat[y][x] = i + 1;
	if (x + 1 < args.x_board && y - 1 >= 0 && args.heat[y - 1][x + 1] == i)
		args.heat[y][x] = i + 1;
	if (x - 1 >= 0 && args.heat[y][x - 1] == i)
		args.heat[y][x] = i + 1;
	if (y - 1 >= 0 && args.heat[y - 1][x] == i)
		args.heat[y][x] = i + 1;
	if (x - 1 >= 0 && y - 1 >= 0 && args.heat[y - 1][x - 1] == i)
		args.heat[y][x] = i + 1;
	if (x - 1 >= 0 && y + 1 < args.y_board && args.heat[y + 1][x - 1] == i)
		args.heat[y][x] = i + 1;
	return (args);
}

t_lt	put_numbers_in_heat(t_lt args)
{
	int x;
	int y;
	int i;

	x = 0;
	y = 0;
	i = 1;
	while (i < args.x_board)
	{
		while (y < args.y_board)
		{
			while (x++ < args.x_board)
			{
				if (args.heat[y][x] == 0)
					put_numbers_in_heat_two(args, i, x, y);
			}
			x = 0;
			y++;
		}
		x = 0;
		y = 0;
		i++;
	}
	i = 0;
	return (args);
}
