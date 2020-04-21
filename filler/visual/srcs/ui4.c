/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui4.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/28 16:58:39 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/28 16:58:40 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static void		print_lines_7(t_all *all, int temp)
{
	int x;
	int y;
	int i;
	int j;

	y = 140;
	j = 106;
	i = (all->val->y * all->val->scale) + 150;
	while (++y < 150 && j++ && ++i)
	{
		x = 44;
		while (++x <= (all->val->x * all->val->scale) + 55)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, y, temp);
			if (j < 110)
				mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, j, temp);
			if (i < (all->val->y * all->val->scale) + 156)
				mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, i, temp);
		}
	}
}

static void		print_lines_6(t_all *all, int temp)
{
	int x;
	int y;
	int i;
	int j;

	y = 149;
	j = 109;
	while (++y <= ((all->val->y * all->val->scale) + 150) && ++j)
	{
		x = 44;
		i = (all->val->x * all->val->scale) + 50;
		while (++x < 50 && ++i <= (all->val->x * all->val->scale) + 55)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, y, temp);
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, i, y, temp);
			if (j <= 140)
			{
				mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, j, temp);
				mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, i, j, temp);
			}
		}
	}
	print_lines_7(all, temp);
}

void			print_lines_5(t_all *all, int temp)
{
	int x;
	int y;
	int j;

	y = -1;
	j = (all->val->y * all->val->scale) + 196;
	while (++y <= 4 && ++j <= (all->val->y * all->val->scale) + 200)
	{
		x = -1;
		while (++x <= (all->val->x * all->val->scale) + 100)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, y, temp);
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			x, j, temp);
		}
	}
	print_lines_6(all, temp);
}
