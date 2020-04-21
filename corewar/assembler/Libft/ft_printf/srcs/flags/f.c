/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:49:58 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:20:24 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	f_input(t_ft *input)
{
	if (input->dot == 0)
	{
		if (input->l != 0)
			input->temp = pt_ftoa_l(va_arg(input->vl, long double),\
			input->after, input->temp, input->temp2);
		else
			input->temp = pt_ftoa(va_arg(input->vl, double),\
			input->after, input->temp, input->temp2);
	}
	else
	{
		if (input->l != 0)
			input->temp = pt_ftoa_l(va_arg(input->vl, long double),\
			input->prec, input->temp, input->temp2);
		else
			input->temp = pt_ftoa(va_arg(input->vl, double),\
			input->prec, input->temp, input->temp2);
	}
}

void		ft_f_out(t_ft *input, int *j)
{
	f_input(input);
	if (input->hash == 1 && input->dot == 1 && input->prec == 0)
		input->temp[ft_strlen(input->temp)] = '.';
	space_sign_placer(input);
	widthconv_str(input, j);
}
