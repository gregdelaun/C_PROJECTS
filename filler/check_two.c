/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_two.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 21:58:25 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 21:58:48 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	free_two_day_tab(char **res)
{
	int i;

	i = 0;
	while (res[i])
	{
		ft_strdel(&res[i]);
		i++;
	}
	free(res);
}

void	print_result(p_lt fuck)
{
	ft_putnbr(fuck.final_y - fuck.plushaut);
	ft_putchar(' ');
	ft_putnbr(fuck.final_x - fuck.plusgauche);
	ft_putchar('\n');
}

int		check_colom(t_lt args, int j)
{
	int i;

	i = 0;
	while (args.tok[i])
	{
		if (args.tok[i][j] == '1' && j == 0)
			return (999);
		else if (args.tok[i][j] == '1')
			return (j);
		i++;
	}
	return (0);
}

int		check_colom_two(t_lt args, int j)
{
	int i;

	i = 0;
	while (args.tok[i])
	{
		if (args.tok[i][j] == '1' && j == 0)
			return (999);
		else if (args.tok[i][j] == '1')
			return (j);
		i++;
	}
	return (0);
}

t_lt	do_smaller_token_two(t_lt args, int tmp2)
{
	while (args.tok[args.i])
	{
		args.j = 0;
		while (args.tok[args.i][args.j])
		{
			if (args.tok[args.i][args.j] == '1' && tmp2 == 0)
			{
				args.haut = args.i;
				tmp2 = 1;
			}
			args.j++;
		}
		args.i++;
	}
	return (args);
}
