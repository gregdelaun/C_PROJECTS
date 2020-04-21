/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/09 13:09:46 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/09 13:14:24 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long temp;

	temp = n;
	if (temp < 0)
	{
		temp *= -1;
		ft_putchar_fd('-', fd);
	}
	if (temp >= 0 && temp < 10)
		ft_putchar_fd(temp + '0', fd);
	else if (temp >= 10)
	{
		ft_putnbr_fd(temp / 10, fd);
		ft_putchar_fd((temp % 10) + '0', fd);
	}
}
