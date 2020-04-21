/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:28:52 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:29:37 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	plus_minus_check(t_ft *input)
{
	int i;

	if (ft_isprintfflag(input->f) && input->pad == '0')
	{
		i = 0;
		while (i < input->width)
		{
			if (input->temp[i] == '-' || input->temp[i] == '+')
				ft_charswap(&input->temp[i], &input->temp[0]);
			i++;
		}
	}
}

void		space_sign_placer(t_ft *input)
{
	if (input->space == 1 && input->sign == 0 && input->temp[0] != '-')
		pt_charput_c_rot(&input->temp, ' ', 0, 1);
	if (input->sign == 1 && input->temp[0] != '-')
		pt_charput_c_rot(&input->temp, '+', 0, 1);
	if (input->f == 'd' || input->f == 'D' || input->f == 'i')
		sign_replacer(input);
}

void		left_align(t_ft *input, int i)
{
	ft_memset(input->temp, ' ', i);
	ft_memmove(input->temp, input->temp2, ft_strlen(input->temp2));
	plus_minus_check(input);
}

void		right_align(t_ft *input, int i)
{
	ft_memset(input->temp, input->pad, i);
	input->temp = ft_strrevcpy(input->temp, input->temp2);
	plus_minus_check(input);
}

void		no_align(t_ft *input, int *j)
{
	input->buff = ft_strcat(input->buff, input->temp);
	*j += ft_strlen(input->temp);
}
