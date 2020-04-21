/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iswhitespace.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 14:52:47 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/03/08 14:52:51 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_iswhitespace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}

int		ft_iswhitespace2(int c)
{
	if (c == '\f' || c == '\n'
			|| c == '\r' || c == '\t' || c == '\v')
		return (1);
	else
		return (0);
}
