/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/30 22:01:33 by grde-lau          #+#    #+#             */
/*   Updated: 2019/10/30 22:01:50 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*gnl_join(char *s1, char *s2)
{
	char *tmp;

	tmp = ft_strdup(s1);
	s1 = ft_strjoin(tmp, s2);
	return (s1);
}

static int	gnl_read(int const fd, char *tmpline, char *tmpbuf[0], char **line)
{
	char	buf[BUFF_SIZE + 1];
	char	*tmpsub;
	int		ret;
	int		i;

	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		i = 0;
		buf[ret] = '\0';
		while ((buf[i] != '\n' && buf[i] != '\0') && i < BUFF_SIZE)
			i++;
		tmpsub = ft_strsub(buf, 0, i);
		tmpline = gnl_join(tmpline, tmpsub);
		*line = tmpline;
		if (buf[i] == '\0' && i != BUFF_SIZE)
			buf[i] = '\n';
		else if (buf[i] == '\n' && (tmpbuf[fd] = ft_strdup(&buf[i + 1])))
		{
			return (1);
		}
	}
	i = (tmpline[0] != '\0') ? 1 : 0;
	i = (ret < 0) ? -1 : i;
	return (i);
}

int			ft_get_next_line(int const fd, char **line)
{
	static char		*tmpbuf[256];
	char			*tmpl;
	char			*tmp;
	int				i;

	if (!line || fd < 0 || fd > 256 || !(tmpl = (char *)malloc(BUFF_SIZE + 1)))
		return (-1);
	*line = tmpl;
	tmpbuf[fd] != NULL ? tmp = ft_strdup(tmpbuf[fd]) : 0;
	ft_bzero(tmpl, BUFF_SIZE);
	i = 0;
	while (tmp != NULL && tmp[i] != '\0')
	{
		if (tmp[i] == '\n')
		{
			tmpbuf[fd] = ft_strdup(&tmp[i + 1]);
			return (1);
		}
		tmpl = gnl_join(tmpl, ft_strsub(tmp, i++, 1));
		*line = tmpl;
	}
	tmpbuf[fd] = &tmp[i];
	i = gnl_read(fd, tmpl, tmpbuf, line);
	i = (tmpl[0] != '\0') ? 1 : i;
	return (i);
}
