/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:36 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:50:37 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	u_input(t_ft *input)
{
	if (input->j == 1)
		input->temp = pt_itoa_uint_j(va_arg(input->vl, uintmax_t), input->temp);
	else if (input->l == 2 || input->f == 'U')
		input->temp = pt_itoa_uint_ll(va_arg(input->vl, unsigned long long),\
		input->temp);
	else if (input->z == 1)
		input->temp = pt_itoa_uint_z(va_arg(input->vl, size_t), input->temp);
	else if (input->l == 1)
		input->temp = pt_itoa_uint_l(va_arg(input->vl, unsigned long),\
		input->temp);
	else if (input->h == 1)
		input->temp = pt_itoa_uint_h(va_arg(input->vl, unsigned int),\
		input->temp);
	else if (input->h == 2)
		input->temp = pt_itoa_uint_hh(va_arg(input->vl, unsigned int),\
		input->temp);
	else
		input->temp = pt_itoa_uint(va_arg(input->vl, unsigned int),\
		input->temp);
}

void		ft_u_out(t_ft *input, int *j)
{
	int i;

	i = ft_intmakepos(input->width);
	input->space = 0;
	input->sign = 0;
	u_input(input);
	space_sign_placer(input);
	if (input->dot == 1)
		put_prec_dioux(input);
	widthconv_str(input, j);
}
