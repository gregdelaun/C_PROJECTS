/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtoupper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 13:06:07 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/19 13:06:08 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strtoupper(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_chartoupper(str[i]);
		i++;
	}
	return (str);
}
