/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/08 13:03:32 by fabbenbr          #+#    #+#             */
/*   Updated: 2018/10/13 13:34:45 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnew(size_t size)
{
	void	*tmem;

	if ((tmem = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	else
		return (ft_memset(tmem, '\0', size + 1));
}
