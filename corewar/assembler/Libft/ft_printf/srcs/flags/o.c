/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:13 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:50:16 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	o_input(t_ft *input)
{
	if (input->j == 1)
		input->temp = pt_intoctal_j(va_arg(input->vl, uintmax_t), input->temp);
	else if (input->l == 2 || input->f == 'O')
		input->temp = pt_intoctal_ll(va_arg(input->vl, unsigned long long int),\
		input->temp);
	else if (input->z == 1)
		input->temp = pt_intoctal_z(va_arg(input->vl, size_t), input->temp);
	else if (input->l == 1)
		input->temp = pt_intoctal_l(va_arg(input->vl, unsigned long int),\
		input->temp);
	else if (input->h == 1)
		input->temp = pt_intoctal_h(va_arg(input->vl, unsigned int),\
		input->temp);
	else if (input->h == 2)
		input->temp = pt_intoctal_hh(va_arg(input->vl, unsigned int),\
		input->temp);
	else
		input->temp = pt_intoctal(va_arg(input->vl, unsigned int), input->temp);
}

void		ft_o_out(t_ft *input, int *j)
{
	o_input(input);
	if (input->dot == 1)
		put_prec_dioux(input);
	if (input->hash == 1 && input->temp[0] != '0')
		pt_charput_c_rot(&input->temp, '0', 0, 1);
	widthconv_str(input, j);
}
