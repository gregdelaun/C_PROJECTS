/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 12:14:44 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/25 15:38:16 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	wordc(char const *s, char c)
{
	int		i;
	int		words;
	int		isword;

	i = 0;
	isword = 0;
	if (s[0] != c)
		words = 1;
	else
		words = 0;
	while (s[i])
	{
		while (s[i] != c && s[i])
		{
			i++;
			isword = 1;
		}
		if (s[i] == c && s[i])
		{
			words += (isword == 1) ? 1 : 0;
			isword = 0;
			i++;
		}
	}
	return (words);
}

static int	wordl(const char *str, char c, int i)
{
	int		counter;

	counter = 0;
	while (str[i] != c && str[i] != '\0')
	{
		counter++;
		i++;
	}
	return (counter);
}

static void	setvalues(int *i, int *j)
{
	*i = 0;
	*j = 0;
}

static int	splitter(const char *s, char c, int i, int *x)
{
	*x = 0;
	while (s[i] == c && s[i])
		i++;
	return (i);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**t;
	int		i;
	int		j;
	int		x;

	setvalues(&i, &j);
	if (!s || !c || (t = (char **)malloc(sizeof(*t) * wordc(s, c) + 1)) == NULL)
		return (NULL);
	while (s[i])
	{
		i = splitter(s, c, i, &x);
		if (s[i])
		{
			if ((t[j] = malloc(sizeof(char) * wordl(s, c, i) + 1)) == NULL)
			{
				free(*t);
				return (NULL);
			}
			while (s[i] != c && s[i])
				t[j][x++] = s[i++];
			t[j++][x] = '\0';
		}
	}
	t[j] = NULL;
	return (t);
}
