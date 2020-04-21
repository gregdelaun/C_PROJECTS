/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_strrot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:08:46 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 12:08:47 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	pt_strrot(char **str, int n)
{
	char	*temp;
	int		i;

	temp = *str;
	if (n > 0)
	{
		i = ft_strlen(temp);
		while (i--)
		{
			if (i + n >= 0)
				ft_charswap(&temp[i + n], &temp[i]);
		}
	}
	else
	{
		i = 0;
		while (temp[++i] != '\0')
		{
			if (i + n >= 0)
				ft_charswap(&temp[i + n], &temp[i]);
		}
	}
}
