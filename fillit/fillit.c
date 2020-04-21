/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 15:32:38 by quroba            #+#    #+#             */
/*   Updated: 2019/05/20 13:45:13 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int argc, char const *argv[])
{
	int		fd;
	char	*buf;

	fd = 0;
	if (argc != 2)
	{
		ft_putstr("usage : ./fillit [tetro]\n");
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	buf = NULL;
	if (!(buf = get_tetri(buf, fd))
			|| check_error(buf, ft_strlen(buf), ft_strlen(buf))
			|| count_hashtag(buf) || (g_nbr_tetrimonis > 26 || buf[0] == '\0'))
	{
		free(buf);
		ft_putstr("error\n");
		return (0);
	}
	if (read_file(&buf))
		ft_putstr("error\n");
	return (0);
}

int		read_file(char **buf)
{
	t_lst	*list;
	char	**tab;

	if (!(tab = put_in_tab((*buf))))
	{
		free(*buf);
		return (1);
	}
	free(*buf);
	if ((list = put_tab_in_list(tab)) == NULL || move_tab(list) == 1)
	{
		free_tab2(tab);
		free_list(list);
		return (1);
	}
	free_tab2(tab);
	free_list(list);
	return (0);
}

char	*get_tetri(char *buf, int fd)
{
	char	*temp;
	int		ret;

	if ((temp = ft_strnew(1)) == NULL
			|| (buf = ft_strnew(1)) == NULL)
		return (NULL);
	while ((ret = read(fd, temp, 1)) > 0)
	{
		temp[ret] = '\0';
		buf = ft_strjoinfree(buf, temp, 1);
		if ((temp = ft_strnew(1)) == NULL)
			return (NULL);
	}
	if (ret < 0)
	{
		free(buf);
		free(temp);
		return (NULL);
	}
	free(temp);
	g_nbr_tetrimonis = get_nbr_tetromonis(buf);
	return (buf);
}

int		get_nbr_tetromonis(char *buf)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (buf[i])
	{
		if (buf[i] == '\n' && (buf[i + 1] == '\n' || buf[i + 1] == '\0'))
			c++;
		i++;
	}
	return (c);
}

t_lst	*free_list(t_lst *list)
{
	char	**tmp;
	t_lst	*next;

	while (list)
	{
		tmp = list->tab;
		next = list->next;
		free_tab2(tmp);
		ft_memdel((void **)&list);
		list = next;
	}
	return (NULL);
}
