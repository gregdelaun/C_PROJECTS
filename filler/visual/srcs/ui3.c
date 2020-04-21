/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:58:34 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/28 16:58:35 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static void	print_lines_4(t_all *all, int temp)
{
	int x;
	int y;
	int i;

	y = -1;
	while (++y <= ((all->val->y * all->val->scale) + 200))
	{
		x = -1;
		i = (all->val->x * all->val->scale) + 95;
		while (++x <= 3 && ++i <= (all->val->x * all->val->scale) + 100)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			i, y, temp);
		}
	}
	print_lines_5(all, temp);
}

static void	print_lines_3(t_all *all, int temp)
{
	int x;
	int y;

	y = 7;
	while (++y < 103)
	{
		x = ((all->val->x * all->val->scale) + 100) / 2 - 49;
		while (++x <= ((all->val->x * all->val->scale) + 100) / 2 - 45)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
	}
	y = 7;
	while (++y < 103)
	{
		x = ((all->val->x * all->val->scale) + 100) / 2 + 45;
		while (++x <= ((all->val->x * all->val->scale) + 100) / 2 + 48)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
	}
	print_lines_4(all, temp);
}

static void	print_lines_2(t_all *all, int temp)
{
	int x;
	int y;

	y = 7;
	while (++y < 10)
	{
		x = ((all->val->x * all->val->scale) + 100) / 2 - 46;
		while (++x <= ((all->val->x * all->val->scale) + 100) / 2 + 45)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
	}
	y = 100;
	while (++y < 103)
	{
		x = ((all->val->x * all->val->scale) + 100) / 2 - 46;
		while (++x <= ((all->val->x * all->val->scale) + 100) / 2 + 45)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
	}
	print_lines_3(all, temp);
}

static int	get_color(int bg1, int bg2)
{
	if (bg1 > bg2)
		return ((bg1 - bg2) / 2 + bg2);
	else if (bg1 < bg2)
		return ((bg2 - bg1) / 2 + bg1);
	return (0);
}

void		print_lines(t_all *all)
{
	int temp;
	int x;
	int y;

	temp = get_color(all->win->bg1, all->win->bg3);
	y = 79;
	while (++y <= 82)
	{
		x = -1;
		while (++x <= ((all->val->x * all->val->scale) + 100) / 2 - 46)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
	}
	y = 79;
	while (++y <= 82)
	{
		x = ((all->val->x * all->val->scale) + 100) / 2 + 45;
		while (++x <= all->val->x * all->val->scale + 200)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
	}
	print_lines_2(all, temp);
}
