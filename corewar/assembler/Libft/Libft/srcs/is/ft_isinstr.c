/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isinstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 13:43:16 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/10/10 13:43:17 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_isinstr(char *in, int c)
{
	int	i;

	i = -1;
	while (in[++i] != '\0')
		if (in[i] == c)
			return (1);
	return (0);
}
