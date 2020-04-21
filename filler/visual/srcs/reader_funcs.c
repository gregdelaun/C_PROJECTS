/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader_funcs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:29 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:30 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Reads player name through gnl
*/

static int		player_name(t_all *all, char *line)
{
	if (ft_strncmp(line, "$$$ exec p1", 11) == 0)
	{
		if (!(all->win->player1 = init_player_name(line)))
			program_quit(all);
		all->p1 = 1;
	}
	else if (ft_strncmp(line, "$$$ exec p2", 11) == 0)
	{
		if (!(all->win->player2 = init_player_name(line)))
			program_quit(all);
		all->p2 = 1;
	}
	return (1);
}

/*
**	Sets up the information needed to launch the window
*/

static t_all	*set_up_screeninfo(t_all *all)
{
	all->val->scale = select_scale(all->val->x, all->val->y);
	if (!(all->rep_arr = new_replay_array(all->val->x * all->val->y)) ||\
	!(all->win->title = make_title(all->win->player1, all->win->player2)) ||\
	!(all->win = init_window(all)) ||\
	all->val->x == 0 || all->val->y == 0)
		program_quit(all);
	return (all);
}

/*
**	Reads the starting map and first token in order to
**	launch the window
*/

static int		init_maptoken(char *line, t_all *all)
{
	if (ft_strncmp(line, "Plateau", 7) == 0)
	{
		get_map_size(line, &all->val->x, &all->val->y);
		if (all->p1 == 0 || all->p2 == 0 || !(all = set_up_screeninfo(all)))
			program_quit(all);
		if (map_fillers(line, all, 3) == 0)
			program_quit(all);
	}
	if (ft_strncmp(line, "Piece", 5) == 0)
	{
		if (map_fillers(line, all, 0) == 0)
			program_quit(all);
		return (2);
	}
	return (1);
}

/*
**	initializing gnl, in case of error with filler_vm the program
**	closes
*/

t_all			*init_gnl(t_all *all)
{
	char	*line;
	int		i;

	i = 1;
	while (i)
	{
		if (!(get_next_line(0, &line)) || ft_strncmp(line, "error:", 6) == 0 ||\
		ft_strncmp(line, "Usage:", 6) == 0 || !(player_name(all, line)) ||\
		(i = init_maptoken(line, all)) == 0)
		{
			free(line);
			program_quit(all);
		}
		if (i == 2)
		{
			free(line);
			break ;
		}
		free(line);
	}
	return (all);
}
