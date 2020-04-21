/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:49:33 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:49:36 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_char_out(int c, t_ft *input, int *j)
{
	if (c == 0)
		input->c0 += 1;
	if (input->width == 0)
	{
		input->buff = ft_charcat(input->buff, c);
		*j += 1;
	}
	else
		widthconv_c(input, j, c);
}
