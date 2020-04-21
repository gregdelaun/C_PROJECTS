/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:49:26 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:49:27 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

void	ft_b_out(t_ft *input, int *j)
{
	input->temp = pt_dectobin(va_arg(input->vl, int), input->temp);
	widthconv_str(input, j);
}
