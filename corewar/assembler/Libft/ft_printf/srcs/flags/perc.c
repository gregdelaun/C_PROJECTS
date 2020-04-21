/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   perc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:27 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:50:28 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_percentage(t_ft *input, int *j)
{
	if (input->width == 0)
	{
		input->buff = ft_charcat(input->buff, input->f);
		*j += 1;
	}
	else
		widthconv_c(input, j, input->f);
}
