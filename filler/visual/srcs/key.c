/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:02 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:03 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Function for closing the winodw. Works with
**	the escape key and the X button at the top of the window
*/

int			windowclose(void *all)
{
	free_all(all);
	ft_printf("Filler visualitation closed successfully.\n");
	exit(0);
}

/*
**	Update function draws the changes onto the screen
*/

static void	update(t_all *all, int i)
{
	print_background_2(all);
	print_playernames(all);
	draw_map(all, -i);
	update_print_score(all, -i);
	fill_score(all);
	draw_token(all, -i);
}

/*
**	The move function is used to go to the next or
**	previous position in the pointer rep_arr
**	This function is only called when pressing the left
**	or right arrow
*/

static int	move(void *param, int i)
{
	t_all *all;

	all = (t_all *)param;
	if (all->rep_arr[all->val->rep + i] != NULL && all->val->rep + i >= 0)
	{
		all->val->rep += i;
		update(all, i);
	}
	return (1);
}

/*
**	move_forward is an automated function for reading the output
**	of filler_vm and moving forward in rep_arr
*/

int			move_forward(void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (all->gnl == 1)
		loop_gnl(param);
	if (all->rep_arr[all->val->rep + 1] != NULL && all->win->pause == 0)
	{
		all->val->rep += 1;
		update(all, 1);
	}
	return (0);
}

/*
**	Function for key press handling, every key pressed
**	will set the variable pause back to 1, stopping the
**	automated updating of the screen
*/

int			key_press(int keycode, void *param)
{
	t_all *all;

	all = (t_all*)param;
	if (keycode == 124)
		move(all, 1);
	else if (keycode == 123)
		move(all, -1);
	else if (keycode == 49)
	{
		all->win->pause = (all->win->pause == 0) ? 1 : 0;
		return (1);
	}
	else if (keycode == 15)
	{
		all->win->pause = 1;
		all->val->rep = 0;
		reset_ui(all);
	}
	else if (keycode == 53)
		windowclose(all);
	all->win->pause = 1;
	return (1);
}
