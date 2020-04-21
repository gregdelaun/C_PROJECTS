/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 11:39:08 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/24 11:39:09 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visual.h"

/*
**	Prints help by using -h
*/

static void	print_help(void)
{
	ft_printf("Usage: This program must be launched with the filler_vm\n");
	ft_printf("and it only works in multiplayer mode.\n\n");
	ft_printf("In order to set player colors:            -p1 [color]\n");
	ft_printf("                                          -p2 [color]\n\n");
	ft_printf("Background colors can be set by:          -bg1 [color]\n");
	ft_printf("                                          -bg2 [color]\n");
	ft_printf("                                          -bg3 [color]\n");
	ft_printf("Color input can be decimal, hexadecimal or color name.\n");
	ft_printf("Following color names are available:      red\n");
	ft_printf("                                          blue\n");
	ft_printf("                                          green\n");
	ft_printf("                                          purple\n");
	ft_printf("                                          brown\n");
	ft_printf("                                          pink\n");
	ft_printf("                                          orange\n");
	ft_printf("                                          yellow\n");
	ft_printf("Following keys can be used:       Pause : space\n");
	ft_printf("                                  Reset : R\n");
	ft_printf("                                Forward : Right Arrow\n");
	ft_printf("                               Backward : Left Arrow\n");
}

/*
**	Main mallocs the structure t_all with most necessary mallocs
**	Afterwards it will draw all of the information given into the
**	window and then launch it.
*/

int			main(int argc, char **argv)
{
	t_all	*all;

	if (argc > 1 && ft_strcmp(argv[1], "-h") == 0)
	{
		print_help();
		return (0);
	}
	all = NULL;
	if (!(all = malloc_lists(argc, argv)))
		program_quit(all);
	draw_start(all);
	draw_start_token(all);
	fill_score(all);
	game_loop(all);
	return (0);
}
