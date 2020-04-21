/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui_score.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:40:06 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:40:07 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

static void	draw_score_p1(t_all *all, int start, int end, int color)
{
	int i;
	int x;

	i = 111;
	x = start;
	while (i < 140)
	{
		start = x;
		while (start < end - 1)
		{
			mlx_pixel_put(all->win->mlx_ptr,\
			all->win->win_ptr, start, i, color);
			start++;
		}
		i++;
	}
}

/*
**	Draws the bar with the colors of both players
*/

void		draw_score(t_all *all, int start, int end, int color)
{
	int i;
	int x;

	i = 111;
	x = start;
	if (start < end)
	{
		draw_score_p1(all, start, end, color);
		return ;
	}
	while (i < 140)
	{
		start = x;
		while (start > end)
		{
			mlx_pixel_put(all->win->mlx_ptr,\
			all->win->win_ptr, start, i, color);
			start--;
		}
		i++;
	}
}

/*
**	fills the bar
*/

void		fill_score(t_all *all)
{
	int	p1;
	int	p2;
	int	total;
	int	perc;

	if (all->val->rep == 0)
	{
		draw_score(all, 51, (all->val->x * all->val->scale + 50) / 2,\
		all->win->col_p1);
		draw_score(all, (all->val->x * all->val->scale + 50) / 2,\
		(all->val->x * all->val->scale + 50), all->win->col_p2);
	}
	if (ft_strcmp(all->rep_arr[all->val->rep]->p1_score, "0") != 0 &&\
	ft_strcmp(all->rep_arr[all->val->rep]->p1_score, "0") != 0)
	{
		p1 = ft_atoi(all->rep_arr[all->val->rep]->p1_score);
		p2 = ft_atoi(all->rep_arr[all->val->rep]->p2_score);
		total = p1 + p2;
		perc = (all->val->x * all->val->scale + 50) * p1 / total + 1;
		draw_score(all, 51, (int)perc, all->win->col_p1);
		perc = (all->val->x * all->val->scale + 50) * p2 / total + 1;
		draw_score(all, (all->val->x * all->val->scale + 50) - 1,\
		(all->val->x * all->val->scale + 50) - (int)perc, all->win->col_p2);
	}
}

/*
**	Prints the bar used for scores in percentage
*/

void		print_score_ui(t_all *all, int x, int scale)
{
	draw_line_hor(all, 50, x * scale + 50, 110);
	draw_line_hor(all, 50, x * scale + 50, 140);
	draw_line_ver(all, 110, 140, 50);
	draw_line_ver(all, 110, 140, x * scale + 50);
}
