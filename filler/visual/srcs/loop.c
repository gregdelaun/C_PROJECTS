/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 15:44:52 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/06/26 15:44:53 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Called by loop_gnl to know which information to store
**	and when to stop. If output from filler_vm is "=="
**	the variable gnl will be put to 0 and stop reading
*/

static int	check_line(t_all *all, char *line)
{
	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		if (map_fillers(line, all, 1) == 0)
			return (0);
	}
	else if (ft_strncmp(line, "Piece", 5) == 0)
		if (map_fillers(line, all, 0) == 0)
			return (0);
	if (ft_strncmp(line, "== ", 3) == 0)
		all->gnl = 0;
	return (1);
}

/*
**	Function for filler_vm output reading during game_loop
*/

int			loop_gnl(void *param)
{
	t_all	*all;
	char	*line;

	all = (t_all*)param;
	if (!(get_next_line(0, &line)))
	{
		free(line);
		program_quit(all);
	}
	check_line(all, line);
	free(line);
	return (1);
}

/*
**	game_loop keeps the window open
*/

void		game_loop(t_all *all)
{
	mlx_hook(all->win->win_ptr, 2, 0, key_press, all);
	mlx_hook(all->win->win_ptr, 17, 0, windowclose, all);
	mlx_loop_hook(all->win->mlx_ptr, move_forward, all);
	mlx_loop(all->win->mlx_ptr);
}
