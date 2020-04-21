/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grde-lau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:09:28 by grde-lau          #+#    #+#             */
/*   Updated: 2018/11/28 12:12:43 by grde-lau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int i;
	int r;
	int o;

	o = nb;
	r = 1;
	i = 1;
	if (nb >= 13)
		return (0);
	if (nb == 1)
		return (1);
	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	while (nb > i)
	{
		r = r * (nb - 1);
		nb--;
	}
	return (r * o);
}
