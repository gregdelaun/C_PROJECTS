/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 20:45:06 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 21:22:44 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	continue_recusrive(t_lt args, int k, p_lt *fuck)
{
	args.first_x = args.first_x - 1;
	args.w = args.w - 1;
	free_two_day_tab(args.res);
	if (args.w > 1)
	{
		if (args.k < args.save)
			fill_in_or_not_two(args.first_y, args.first_x, args, fuck);
		else if (k == args.save)
		{
			args.k = 0;
			args.first_x = args.first_x + args.save;
			args.first_y = args.first_y - 1;
			fill_in_or_not_two(args.first_y, args.first_x, args, fuck);
		}
	}
}

p_lt	fill_in_or_not_two(int y, int x, t_lt args, p_lt *fuck)
{
	args.w == -5 ? args = init_varaibles(args, x, y) : ft_strdel(NULL);
	args = init_varaibles_two(args, x, y);
	while (args.i < args.save2)
	{
		args.j = 0;
		args.x_token = args.save;
		x = args.save_x;
		while (args.j < args.save)
		{
			if (x >= 0 && x <= (args.x_board - 1)
				&& y >= 0 && y <= (args.y_board - 1))
				args.res[args.i][args.j] =
			args.tab[y][x] + args.tok2[args.i][args.j] - '0';
			args.j++;
			x++;
			args.x_token--;
		}
		args.i++;
		y++;
		args.y_token--;
	}
	*fuck = check_res_board(args.res, args, args.save_x, args.save_y, fuck);
	args.k = args.k + 1;
	args.k <= args.save ? continue_recusrive(args, args.k, fuck) : 0;
	return (*fuck);
}

p_lt	check_valid_position(t_lt args, q_lt *coor, p_lt fuck)
{
	static int p;
	static int o;

	p = 0;
	fuck.on = 0;
	fuck.ok = 0;
	while (coor[p].y != -1 && coor[p].x != -1)
	{
		args.k = 0;
		fill_in_or_not_two(coor[p].y, coor[p].x, args, &fuck);
		p++;
	}
	fuck.plusgauche = args.gauchesave;
	fuck.plushaut = args.hautsave;
	return (fuck);
}

int		check_next_door(t_lt args, int i, int j)
{
	if (i + 1 <= args.y_board - 1 && j + 1 <= args.x_board - 1
		&& i - 1 >= 0 && j - 1 >= 0)
	{
		if (args.tab[args.i][args.j - 1] == '2'
			&& args.tab[args.i - 1][args.j + 1] == '2'
				&& args.tab[args.i][args.j + 1] == '2'
				&& args.tab[args.i + 1][args.j] == '2')
			return (0);
	}
	return (1);
}

int		go_algo(t_lt args)
{
	p_lt	fuck;
	q_lt	coor[args.nbr_two + 1];

	*coor = initialise_variables(&args, &fuck, coor);
	while (args.tab[++args.i])
	{
		args.j = -1;
		while (args.tab[args.i][++args.j])
			if (args.tab[args.i][args.j] == '2'
				&& check_next_door(args, args.i, args.j))
			{
				coor[args.p].x = args.j;
				coor[args.p].y = args.i;
				args.p++;
			}
	}
	fuck = check_valid_position(args, coor, fuck);
	while (args.i != args.y_board)
		free(args.heat[args.i++]);
	fuck.ok == 1 ? print_result(fuck) : 0;
	!(fuck.ok == 1) ? ft_putstr("0 0\n") : 0;
	!(fuck.ok == 1) ? exit(0) : 0;
	return (1);
}
