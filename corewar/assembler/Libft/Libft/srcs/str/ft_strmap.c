/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/13 13:33:19 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/13 13:46:08 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		j;
	char	*str;

	if (!s && !f)
		return (NULL);
	i = 0;
	j = ft_strlen((char *)s);
	if ((str = ft_strnew(j)) == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(s[i]);
		i++;
	}
	return (str);
}
