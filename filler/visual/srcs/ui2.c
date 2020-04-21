/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui2.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:40:00 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:40:01 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

void	draw_line_hor(t_all *all, int start, int end, int i)
{
	while (start < end)
	{
		mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			start, i, all->win->bg2);
		start++;
	}
}

void	draw_line_ver(t_all *all, int start, int end, int i)
{
	while (start < end)
	{
		mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			i, start, all->win->bg2);
		start++;
	}
}

void	print_grid(t_all *all, int x, int y, int scale)
{
	int i;
	int j;

	i = 150;
	j = 50;
	while (i <= (y * scale) + 150)
	{
		draw_line_hor(all, 50, x * scale + 50, i);
		i += scale;
	}
	while (j <= (x * scale) + 50)
	{
		draw_line_ver(all, 150, y * scale + 150, j);
		j += scale;
	}
}

void	print_piece_ui(t_all *all, int x, int scale)
{
	int i;
	int j;
	int z;

	i = ((x * scale) + 100) / 2 - 45;
	j = ((x * scale) + 100) / 2 + 45;
	z = 10;
	while (z <= 100)
	{
		draw_line_hor(all, i, j, z);
		draw_line_hor(all, i, j, z);
		z += 10;
	}
	z = i;
	while (z <= j)
	{
		draw_line_ver(all, 10, 100, z);
		draw_line_ver(all, 10, 100, z);
		z += 10;
	}
}

void	print_background(t_all *all)
{
	int	start;
	int	y;

	y = 0;
	start = 0;
	while (y < all->val->y * all->val->scale + 200)
	{
		start = 0;
		while (start < all->val->x * all->val->scale + 100)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			start, y, all->win->bg1);
			start++;
		}
		y++;
	}
}
