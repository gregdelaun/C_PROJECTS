/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 14:02:30 by quroba            #+#    #+#             */
/*   Updated: 2018/11/27 13:53:48 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char			*str;
	unsigned int	i;
	size_t			lg;

	i = 0;
	if (!s)
		return (NULL);
	lg = ft_strlen(s);
	while (((s[i] == ' ') || (s[i] == '\n') || (s[i] == '\t'))
		&& (s[i] != '\0'))
		i++;
	while ((s[lg - 1] == ' ' || s[lg - 1] == '\n' || s[lg - 1] == '\t')
		&& (s[i] != '\0'))
		lg--;
	str = ft_strsub(s, i, (lg - i));
	if (str)
		return (str);
	return (NULL);
}
