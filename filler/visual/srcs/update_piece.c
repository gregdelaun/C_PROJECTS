/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:40:16 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:40:17 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Fills in the boxes of preview token
*/

void	fill_box_token(int x, int y, int color, t_all *all)
{
	int i;
	int j;
	int u;
	int	z;

	i = ((all->val->x * all->val->scale) + 100) / 2 - 45 + (x * 10) + 1;
	j = i + 9;
	u = y * 10 + 11;
	z = u + 9;
	while (u < z)
	{
		i = ((all->val->x * all->val->scale) + 100) / 2 - 45 + (x * 10) + 1;
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
**	Clears all of the tokens
*/

void	clear_box_token(int x, int y, t_all *all)
{
	int i;
	int j;
	int u;
	int	z;

	i = ((all->val->x * all->val->scale) + 100) / 2 - 45 + (x * 10) + 1;
	j = i + 9;
	u = y * 10 + 11;
	z = u + 9;
	while (u < z)
	{
		i = ((all->val->x * all->val->scale) + 100) / 2 - 45 + (x * 10) + 1;
		while (i < j)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr,\
			i, u, all->win->bg1);
			i++;
		}
		u++;
	}
}

/*
**	Deletes the token that has just been played from
**	the token preview
*/

void	clear_prev_token(t_all *all, int j)
{
	int x;
	int y;

	y = 0;
	if (all->val->rep + j >= 0)
	{
		while (all->rep_arr[all->val->rep + j]->token[y])
		{
			x = 0;
			while (all->rep_arr[all->val->rep + j]->token[y][x])
			{
				if (all->rep_arr[all->val->rep + j]->token[y][x] == '*')
					clear_box_token(x, y, all);
				x++;
			}
			y++;
		}
	}
}

/*
**	Draws the token that will be played on next turn
*/

void	draw_token(t_all *all, int j)
{
	int x;
	int y;

	clear_prev_token(all, j);
	y = 0;
	while (all->rep_arr[all->val->rep]->token[y])
	{
		x = 0;
		while (all->rep_arr[all->val->rep]->token[y][x])
		{
			if (all->rep_arr[all->val->rep]->token[y][x] == '*')
				fill_box_token(x, y, 0xffffff, all);
			x++;
		}
		y++;
	}
}

/*
**	Draws the first token
*/

void	draw_start_token(t_all *all)
{
	int x;
	int y;

	y = 0;
	while (all->rep_arr[0]->token[y])
	{
		x = 0;
		while (all->rep_arr[0]->token[y][x])
		{
			if (all->rep_arr[0]->token[y][x] == '*')
				fill_box_token(x, y, 0xffffff, all);
			x++;
		}
		y++;
	}
}
