/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quroba <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:36:28 by quroba            #+#    #+#             */
/*   Updated: 2019/03/06 15:38:31 by quroba           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfree(char *s1, char *s2, int frees)
{
	char	*str;

	if (!(str = ft_strjoin(s1, s2)))
		return (NULL);
	free(s1);
	s1 = NULL;
	if (frees)
	{
		free(s2);
		s2 = NULL;
	}
	return (str);
}
