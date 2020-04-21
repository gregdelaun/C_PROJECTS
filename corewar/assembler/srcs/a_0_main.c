/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_0_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 13:58:10 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 13:59:07 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

/*
**	checks if the file is of ".s" type
*/

static int		check_file(char *av)
{
	if (ft_strncmp(ft_strrchr(av, '.'), ".s", 2) == 0)
		return (1);
	return (0);
}

/*
**	gets the filename in order to create the .cor file
*/

static void		get_filename(t_all *all, char *av)
{
	char	*str;
	int		i;

	i = -1;
	str = NULL;
	while (av[++i])
		if (ft_strncmp(&av[i], ".s", 2) == 0)
			break ;
	if (!(str = ft_strnew(i + 3)))
		error_message("Error\n", all, NULL);
	str = ft_strncpy(str, av, i);
	str = ft_strcat(str, ".cor");
	all->file = str;
}

/*
**	inits all structure
*/

static t_all	*init_all(void)
{
	t_all	*all;

	if (!(all = (t_all*)ft_memalloc(sizeof(t_all))))
		return (NULL);
	all->champ_name = 0;
	all->champ_comm = 0;
	all->file = NULL;
	all->len = 0;
	all->result = NULL;
	all->i.args = NULL;
	all->l = NULL;
	return (all);
}

/*
**	checks if there is a file in the arguments and if it is valid
*/

static void		ac_file_check(int ac, char **av)
{
	if (ac <= 1 || check_file(av[1]) == 0)
	{
		ft_putendl("No file or wrong filetype");
		exit(0);
	}
}

/*
**	Start of the program
*/

int				main(int ac, char **av)
{
	t_all	*all;
	int		fd;

	ac_file_check(ac, av);
	if ((all = init_all()) == NULL)
		error_message("Malloc error\n", all, NULL);
	get_filename(all, av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
	{
		close(fd);
		error_message("Error while opening file or file does not exist\n",\
		all, NULL);
	}
	reader(all, fd);
	all->result = get_result(all);
	create_file(all);
	clean_up(all, NULL);
	return (0);
}
