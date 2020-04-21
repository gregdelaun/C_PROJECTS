/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 15:23:59 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/19 12:18:59 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static int	iswhitespace(char s)
{
	if (s == ' ' || s == ',' || s == '\n' || s == '\t')
		return (1);
	else
		return (0);
}

char		*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*str;

	if (!s)
		return (NULL);
	i = -1;
	j = ft_strlen(s);
	while (iswhitespace(s[j - 1]) == 1 && j - 1 > 0)
		j--;
	while (++i < j && iswhitespace(s[i]) == 1)
		j--;
	if (j <= 0)
		j = 0;
	if ((str = ft_strnew(j)) == NULL)
		return (NULL);
	s += i;
	i = -1;
	while (++i < j)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
