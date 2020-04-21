/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_2_name_comment_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/24 15:37:47 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/24 15:37:49 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	add_the_line(t_all *all, char *line, char *l)
{
	ft_strdel(&all->l->line);
	if (!(all->l->line = ft_strnewncpy(ft_strlen(line), line)))
		error_message("Malloc error\n", all, l);
	ft_strdel(&line);
}

static void	error(t_all *all, char *l, char *line)
{
	ft_strdel(&line);
	error_message("Malloc error\n", all, l);
}

static char	search_in_line(char *line)
{
	int		j;

	j = -1;
	while (line[++j] != '\0')
	{
		if (line[j] == '#' || line[j] == '%' || line[j] == ','\
		|| ft_isdigit(line[j]))
			break ;
	}
	return (line[j]);
}

static void	search_next_line(t_all *all, char *l, int fd, size_t *i)
{
	char	*line;
	char	c;

	if (get_next_line_old(fd, &line) != -1)
	{
		if (line)
		{
			(*i)++;
			c = search_in_line(line);
			if (c == '#' || (c == '\0' && all->l->line[0] == 1))
			{
				ft_strdel(&line);
				search_next_line(all, l, fd, i);
			}
			if (c == '%' || c == ',' || ft_isdigit(c))
				add_the_line(all, line, l);
		}
	}
	else
		error(all, l, line);
}

void		check_for_label(t_all *all, char *line, int fd, size_t *i)
{
	int	k;

	k = 0;
	while (line[k] != '#' && line[k] != '%' && line[k] != ','\
	&& line[k] != '\0')
	{
		if (line[k] == ':')
		{
			if (!(all->l = add_label(all->l, line, 1)))
				error_message("Malloc error\n", all, line);
			break ;
		}
		k++;
	}
	if (line[k] == '\0')
		while (line[--k] != 'r')
			if (k == 0)
				break ;
	if (line[k] == '%' || line[k] == ',' || line[k] == 'r')
		if (!(all->l = add_label(all->l, line, 2)))
			error_message("Malloc error\n", all, line);
	if (k != 0 && all->l->line && all->l->line[0] == 1)
		search_next_line(all, line, fd, i);
	if (k == 0)
		error_message("Error in parameter\n", all, line);
}
