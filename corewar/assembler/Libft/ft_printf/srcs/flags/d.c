/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:49:43 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:49:44 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	dec_input(t_ft *input)
{
	if (input->j == 1)
		input->temp = pt_itoa_j(va_arg(input->vl, intmax_t), input->temp);
	else if (input->l == 2 || input->f == 'D')
		input->temp = pt_itoa_ll(va_arg(input->vl, long long), input->temp);
	else if (input->z == 1)
		input->temp = pt_itoa_z(va_arg(input->vl, size_t), input->temp);
	else if (input->l == 1)
		input->temp = pt_itoa_l(va_arg(input->vl, long), input->temp);
	else if (input->h == 1)
		input->temp = pt_itoa_h(va_arg(input->vl, int), input->temp);
	else if (input->h == 2)
		input->temp = pt_itoa_hh(va_arg(input->vl, int), input->temp);
	else
		input->temp = pt_itoa(va_arg(input->vl, int), input->temp);
}

void		ft_dec_out(t_ft *input, int *j)
{
	dec_input(input);
	if (input->dot == 1)
	{
		if (input->temp[0] != '-')
			input->pad = ' ';
		put_prec_dioux(input);
	}
	space_sign_placer(input);
	widthconv_str(input, j);
}
