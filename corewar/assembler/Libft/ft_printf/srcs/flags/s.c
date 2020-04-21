/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s.c                                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:50:31 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:24:29 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_printf.h"

static void	put_prec(t_ft *input)
{
	input->temp2 = ft_strncpy(input->temp2, input->temp, input->prec);
	ft_strclr(input->temp);
	input->temp = ft_strcpy(input->temp, input->temp2);
}

void		ft_str_out(t_ft *input, int *j)
{
	char *str;

	str = va_arg(input->vl, char *);
	if (str == NULL)
		input->temp = ft_strcpy(input->temp, "(null)");
	else
		input->temp = ft_strcpy(input->temp, str);
	if (input->dot == 1)
		put_prec(input);
	widthconv_str(input, j);
}
