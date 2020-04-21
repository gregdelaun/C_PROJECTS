/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:02:05 by quroba            #+#    #+#             */
/*   Updated: 2018/11/27 13:57:16 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_lenght(char const *s, char c)
{
	size_t a;

	a = 0;
	while (s[a] != c && s[a])
		a++;
	return (a);
}

static int		ft_count(char *s, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (s[i] == c && s[i])
		i++;
	while (s[i])
	{
		while (s[i] != c && s[i])
			i++;
		nb++;
		while (s[i] == c && s[i])
			i++;
	}
	return (nb);
}

static char		*ft_next_word(char const *s, char c)
{
	while (*s && *s == c)
		s++;
	return ((char *)s);
}

static void		ft_free_tab(size_t pos, char **tab)
{
	while (pos > 0)
	{
		pos--;
		ft_strdel(&tab[pos]);
	}
	ft_strdel(tab);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**tab;
	size_t	nb;
	size_t	pos;

	if (!s)
		return (NULL);
	pos = 0;
	nb = ft_count((char *)s, c);
	tab = (char **)ft_memalloc(sizeof(char *) * (nb + 1));
	if (!tab)
		return (NULL);
	while (pos < nb)
	{
		s = ft_next_word(s, c);
		tab[pos] = ft_strsub(s, 0, ft_lenght(s, c));
		if (!(tab[pos]))
		{
			ft_free_tab(pos, tab);
			return (NULL);
		}
		pos++;
		s = s + ft_lenght(s, c);
	}
	tab[nb] = NULL;
	return (tab);
}
