/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:40:40 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/10 13:40:42 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

/*
** Returns the length of the complete string or until the character
** c is found.
*/

size_t	ft_strclen(char *str, int c)
{
	size_t	i;
	size_t	j;

	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] == c)
			j++;
	return (j);
}
