/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:12:53 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 22:17:25 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		count_score(t_lt args, int x, int y, char **res)
{
	static int i;
	static int j;
	static int score;

	i = 0;
	score = 0;
	while (i < args.save2 && y + i > 0 && y + i < args.y_board)
	{
		j = 0;
		while (j < args.save && x + j > 0 && x + j < args.x_board)
		{
			score = score + args.heat[y + i][x + j];
			j++;
		}
		i++;
	}
	return (score);
}

p_lt	compare_save_score(t_lt args, int x, int y, char **res, p_lt *fuck)
{
	int d;
	d = count_score(args, x, y, res);
	if ((fuck->on == 0 || d < fuck->score))
	{
		fuck->score = d;
		fuck->final_x = x;
		fuck->final_y = y;
		fuck->ok = 1;
		fuck->on = 4;
	}
	return (*fuck);
}

p_lt	check_res_board(char **res, t_lt args, int x, int y, p_lt *fuck)
{
	args.a = 0;
	args.b = 0;
	args.c = 0;
	args.i = -1;
	args.count_one = 0;
	while (args.tok2[++args.i])
	{
		args.j = -1;
		while (args.tok2[args.i][++args.j])
			args.tok2[args.i][args.j] == '1' ? args.count_one++ : 0;
	}
	args.i = -1;
	while (res[++args.i])
	{
		args.j = -1;
		while (res[args.i][++args.j])
		{
			res[args.i][args.j] == '3' ? args.a++ : 0;
			res[args.i][args.j] == '1' ? args.b++ : 0;
			res[args.i][args.j] == '2' ? args.c++ : 0;
		}
	}
	if (args.a == 1 && args.b == (args.count_one - 1))
		compare_save_score(args, x, y, res, fuck);
	return (*fuck);
}

char	**create_tab(char **res, int save, int save2)
{
	int i;

	i = 0;
	if (!(res = malloc(sizeof(char*) * (save2 + 1))))
		exit(0);
	while (i < save2)
	{
		if (!(res[i] = malloc(sizeof(char) * (save))))
			exit(0);
		i++;
	}
	res[save2] = NULL;
	return (res);
}

int		main(int argc, char const *argv[])
{
	t_lt	args;
	char	*line;
	int		ret;

	line = NULL;
	if (ft_get_next_line(0, &line) && line && ft_strlen(line) > 10 &&
			!ft_strncmp(line, "$$$ exec p", 9) &&
			(line[10] == '1' || line[10] == '2'))
	{
		args.myplayer_id = (line[10] == '1' ? 'O' : 'X');
		args.nmi_id = (args.myplayer_id == 'O' ? 'X' : 'O');
		ft_strdel(&line);
		while (1)
		{
			init_list(&args);
			ret = several_lenght_checks(&args, line, ret);
			several_lenght_checks_two(&args, line, ret);
			args = create_heat_map(args);
			args = init_the_heat(args);
			args = put_numbers_in_heat(args);
			args.nbr_two = check_numbers_of_two(args);
			args = do_smaller_token(args);
			args = do_new_token(args);
			if (go_algo(args))
				continue;
		}
	}
	else
		return (1);
	return (0);
}
