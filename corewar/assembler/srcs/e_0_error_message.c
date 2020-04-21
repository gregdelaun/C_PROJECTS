/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_0_error_message.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:03:27 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 14:03:28 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	free_all(t_all **all)
{
	if (*all)
	{
		if ((*all)->l != NULL)
			free_labels(&(*all)->l);
		if ((*all)->file != NULL)
			ft_strdel(&(*all)->file);
		if ((*all)->result != NULL)
			ft_strdel(&(*all)->result);
		free(*all);
	}
}

void		free_args(char ***args)
{
	int i;

	i = -1;
	if (*args)
	{
		while (++i < 3)
		{
			if (*args[i])
				ft_strdel(&(*args)[i]);
		}
		free(*args);
		*args = NULL;
	}
}

void		clean_up(t_all *all, char *line)
{
	if (line)
		free(line);
	if (all)
		free_all(&all);
}

void		syntax_error(char *line, char *info)
{
	ft_putstr(line);
	ft_putchar('"');
	ft_putstr(info);
	ft_putendl("\"");
}

void		error_message(char *error, t_all *all, char *line)
{
	ft_putstr(error);
	clean_up(all, line);
	exit(0);
}
