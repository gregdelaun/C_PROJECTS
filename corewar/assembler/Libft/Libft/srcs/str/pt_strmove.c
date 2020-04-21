/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_strmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 12:08:28 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 12:08:30 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*pt_strmove(char *str, char *str2, int n)
{
	int		i;

	i = -1;
	str2 = ft_strcpy(str2, str);
	while (str2[++i])
		str[i + n] = str2[i];
	return (str);
}
