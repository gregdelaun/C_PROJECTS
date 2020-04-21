/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:40:11 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:40:12 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Fills in a box on the grid with a selected color
*/

void	fill_box(int x, int y, int color, t_all *all)
{
	int i;
	int j;
	int u;
	int	z;

	i = x * all->val->scale + 51;
	j = i + all->val->scale - 1;
	u = y * all->val->scale + 151;
	z = u + all->val->scale - 1;
	while (u < z)
	{
		i = x * all->val->scale + 51;
		while (i < j)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			i, u, color);
			i++;
		}
		u++;
	}
}

/*
**	Fills in the boxes in a grid with a highlight
**	to show which piece was placed last
*/

void	latest_played(int x, int y, int color, t_all *all)
{
	int i;
	int j;
	int u;
	int	z;

	i = x * all->val->scale + 51;
	j = i + all->val->scale - 1;
	u = y * all->val->scale + 151;
	z = u + all->val->scale - 1;
	while (u < z)
	{
		i = x * all->val->scale + 51;
		while (i < j)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			i, u, color);
			i++;
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			i, u, 0xffffff);
			i++;
		}
		u++;
	}
}

/*
**	Calls upon fill_box depending on what needs to be updated
*/

void	color_box(t_all *all, int x, int y)
{
	if (all->rep_arr[all->val->rep]->map[y][x] == 'O')
		fill_box(x, y, all->win->col_p1, all);
	else if (all->rep_arr[all->val->rep]->map[y][x] == 'o')
		latest_played(x, y, all->win->col_p1, all);
	else if (all->rep_arr[all->val->rep]->map[y][x] == 'X')
		fill_box(x, y, all->win->col_p2, all);
	else if (all->rep_arr[all->val->rep]->map[y][x] == 'x')
		latest_played(x, y, all->win->col_p2, all);
	else if (all->rep_arr[all->val->rep]->map[y][x] == '.')
		fill_box(x, y, all->win->bg1, all);
}

/*
**	Draws the map by looking what is different with the
**	previous or next map.
*/

void	draw_map(t_all *all, int j)
{
	int x;
	int y;

	y = 0;
	while (all->rep_arr[all->val->rep]->map[y])
	{
		x = 0;
		while (all->rep_arr[all->val->rep]->map[y][x])
		{
			if (all->rep_arr[all->val->rep]->map[y][x] !=\
			all->rep_arr[all->val->rep + j]->map[y][x])
				color_box(all, x, y);
			x++;
		}
		y++;
	}
}

/*
**	Draws the starting grid
*/

void	draw_start(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (all->rep_arr[0]->map[y])
	{
		x = 0;
		while (all->rep_arr[0]->map[y][x])
		{
			if (all->rep_arr[0]->map[y][x] == 'O' ||\
			all->rep_arr[0]->map[y][x] == 'o')
				fill_box(x, y, all->win->col_p1, all);
			else if (all->rep_arr[0]->map[y][x] == 'X' ||\
			all->rep_arr[0]->map[y][x] == 'x')
				fill_box(x, y, all->win->col_p2, all);
			x++;
		}
		y++;
	}
}
