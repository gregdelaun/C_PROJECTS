/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_window.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:38:51 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:38:53 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Calls several functions in order to print
**	the UI of Filler
*/

static void	print_ui(t_all *all)
{
	print_background(all);
	print_strip(all);
	print_lines(all);
	print_background_2(all);
	print_playernames(all);
	print_start_score(all);
	print_piece_ui(all, all->val->x, all->val->scale);
	print_score_ui(all, all->val->x, all->val->scale);
	print_grid(all, all->val->x, all->val->y, all->val->scale);
}

/*
**	Initialises the values needed for the window.
*/

t_window	*init_window(t_all *all)
{
	if (all->val->x < 0 || all->val->y < 0 ||\
	!(all->win->mlx_ptr = mlx_init()) ||
	!(all->win->win_ptr = mlx_new_window(all->win->mlx_ptr,\
	(all->val->x * all->val->scale) + 100,\
	(all->val->y * all->val->scale) + 200, all->win->title)))
		return (NULL);
	print_ui(all);
	return (all->win);
}

/*
**	Function that is used with the 'R' key
**	redraws the UI back to beginning
*/

int			reset_ui(t_all *all)
{
	print_ui(all);
	draw_start(all);
	draw_start_token(all);
	fill_score(all);
	return (1);
}

/*
**	Frees the structure t_window
*/

void		free_window(t_window **w)
{
	if (!w || !*w)
		return ;
	if ((*w)->title != NULL)
		ft_strdel(&(*w)->title);
	if ((*w)->player1 != NULL)
		ft_strdel(&(*w)->player1);
	if ((*w)->player2 != NULL)
		ft_strdel(&(*w)->player2);
	if ((*w)->mlx_ptr && (*w)->win_ptr)
		mlx_destroy_window((*w)->mlx_ptr, (*w)->win_ptr);
	free(*w);
	*w = NULL;
}
