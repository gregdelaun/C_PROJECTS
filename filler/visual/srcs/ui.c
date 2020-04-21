/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:56 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:57 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Updates the score under the player names
*/

void	update_print_score(t_all *all, int j)
{
	int i;

	i = (all->val->x * all->val->scale + 100) -\
	((int)ft_strlen(all->win->player2) * 4) - 30;
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 75, 40,\
		all->win->bg1, all->rep_arr[all->val->rep + j]->p1_score);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, i, 40,\
		all->win->bg1, all->rep_arr[all->val->rep + j]->p2_score);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 75, 40,\
		all->win->col_p1, all->rep_arr[all->val->rep]->p1_score);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, i, 40,\
		all->win->col_p2, all->rep_arr[all->val->rep]->p2_score);
}

/*
**	Prints the starting score of 0 for both players
*/

void	print_start_score(t_all *all)
{
	int i;

	i = (all->val->x * all->val->scale + 100) -\
	((int)ft_strlen(all->win->player2) * 4) - 30;
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 75, 40,\
		all->win->col_p1, "0");
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, i, 40,\
		all->win->col_p2, "0");
}

/*
**	Prints the player names and "Score" underneath
*/

void	print_playernames(t_all *all)
{
	int i;

	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 10, 10,\
	all->win->col_p1, all->win->player1);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, 10, 40,\
	all->win->col_p1, "Score:");
	i = (all->val->x * all->val->scale) -\
	(ft_strlen(all->win->player2) * 3);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, i, 10,\
	all->win->col_p2, all->win->player2);
	mlx_string_put(all->win->mlx_ptr, all->win->win_ptr, i, 40,\
	all->win->col_p2, "Score:");
}

/*
**	Prints the top part of the screen
*/

void	print_strip(t_all *all)
{
	int x;
	int y;

	y = 3;
	while (++y < 8)
	{
		x = ((all->val->x * all->val->scale) + 100) / 2 - 49;
		while (++x <= ((all->val->x * all->val->scale) + 100) / 2 + 48)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, all->win->bg3);
	}
}

/*
**	Prints the lines within the grids
*/

void	print_background_2(t_all *all)
{
	int x;
	int y;

	y = 3;
	while (++y < 80)
	{
		x = 3;
		while (++x <= ((all->val->x * all->val->scale) + 100) / 2 - 49)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, all->win->bg3);
	}
	y = 3;
	while (++y < 80)
	{
		x = ((all->val->x * all->val->scale) + 100) / 2 + 48;
		while (++x <= all->val->x * all->val->scale + 95)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, all->win->bg3);
	}
}
