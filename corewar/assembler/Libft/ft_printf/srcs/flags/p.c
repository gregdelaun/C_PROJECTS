/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:22 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:25:58 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	p_prec(t_ft *input)
{
	if (input->prec == 0 && ft_strcmp(input->temp, "0x0") == 0)
	{
		ft_strclr(input->temp);
		input->temp = ft_strcpy(input->temp, "0x");
	}
	else if ((int)ft_strlen(&input->temp[2]) < input->prec)
	{
		input->temp[1] = '0';
		put_prec_dioux(input);
		input->temp2 = ft_strcpy(input->temp2, "0x");
		input->temp2 = ft_strcat(input->temp2, input->temp);
		ft_strclr(input->temp);
		input->temp = ft_strcpy(input->temp, input->temp2);
	}
}

void		ft_p_out(t_ft *input, int *j)
{
	input->temp = pt_pointeraddress(va_arg(input->vl, void *),\
	input->temp, input->temp2);
	if (input->dot == 1)
		p_prec(input);
	if (input->f == 'P')
		input->temp = ft_strtoupper(input->temp);
	widthconv_str(input, j);
}
