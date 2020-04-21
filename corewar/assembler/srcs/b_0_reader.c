/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_0_reader.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/16 14:00:31 by fabbenbr          #+#    #+#             */
/*   Updated: 2020/01/16 14:00:49 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/asm.h"

static void	invalid_label(t_all *all, char *line, size_t l, size_t j)
{
	ft_putstr("Lexical error at [");
	ft_putnbr(l);
	ft_putchar(':');
	ft_putnbr(j + 1);
	error_message("]\n", all, line);
}

static void	check_line(t_all *all, char *lin, size_t l)
{
	int	i;
	int	j;
	int	x;

	i = -1;
	while (lin[++i] != '\0')
	{
		j = 0;
		x = -1;
		while (++x < 37)
			if (lin[i] == LABEL_CHARS[x])
				j = 1;
		if (lin[i] == ':' || lin[i] == ',' || lin[i] == '%'\
		|| ft_iswhitespace(lin[i]) || lin[i] == '-')
			j = 1;
		if (lin[i] == '#')
			j = 2;
		if (j == 0)
			invalid_label(all, lin, l, i);
		if (j == 2)
			break ;
	}
}

static int	skip_line(t_all *all, char *line, size_t *s)
{
	int i;

	i = 0;
	if (line[0] == ':' || line[0] == '%' || line[0] == ',')
		error_message("Error in read file\n", all, line);
	if (line[0] == COMMENT_CHAR || line[0] == '\0')
	{
		(*s)++;
		ft_strdel(&line);
		return (1);
	}
	while (ft_iswhitespace(line[i]))
		i++;
	if (line[i] == '\0')
	{
		(*s)++;
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

/*
**	input reader from the file
**	starts by reading the name and comment line
*/

void		reader(t_all *all, int fd)
{
	char	*line;
	size_t	i;
	size_t	s;

	i = 1;
	s = 0;
	while (get_next_line_old(fd, &line) > 0)
	{
		if (skip_line(all, line, &s))
			continue ;
		if (ft_strncmp(line, NAME_CMD_STRING, 5) == 0)
			get_name_comment(all, line, 1);
		if (ft_strncmp(line, COMMENT_CMD_STRING, 8) == 0)
			get_name_comment(all, line, 2);
		if (line[0] != '.')
		{
			check_line(all, line, i + s);
			check_for_label(all, line, fd, &i);
		}
		i++;
	}
	close(fd);
	name_comment_check(all, 0, 0);
	reverse_list(all);
}
