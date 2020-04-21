/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_divlen_ul.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/14 10:15:33 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/14 10:15:37 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int		ft_divlen_ul(unsigned long long int n, int divn)
{
	int len;

	len = 1;
	while (n /= divn)
		len++;
	return (len);
}
