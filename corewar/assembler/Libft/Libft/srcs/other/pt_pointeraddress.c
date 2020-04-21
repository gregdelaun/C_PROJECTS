/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_pointeraddress.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:57:19 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:57:20 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*pt_pointeraddress(void *in, char *temp, char *temp2)
{
	long	stack;

	stack = (long)in;
	if (stack == 0)
	{
		temp = ft_strcpy(temp, "0x0");
		return (temp);
	}
	if (stack < 9999999999)
	{
		temp2 = pt_inttohexastr(stack, 0, temp2, temp);
		temp = ft_strcpy(temp, "0x");
		temp = ft_strcat(temp, temp2);
		ft_strclr(temp2);
	}
	else
	{
		temp2 = pt_inttohexastr(stack, 0, temp2, temp);
		temp = ft_strcpy(temp, "0x7fff");
		temp = ft_strcat(temp, temp2);
		ft_strclr(temp2);
	}
	return (temp);
}
