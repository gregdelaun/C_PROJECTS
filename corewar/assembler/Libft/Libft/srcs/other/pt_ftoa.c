/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pt_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fabbenbr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/07 11:55:01 by fabbenbr          #+#    #+#             */
/*   Updated: 2019/05/07 11:55:02 by fabbenbr         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static char		*strfinal(char *tempi, char *tempf, int after, long double n)
{
	int		i;
	char	*res;

	res = tempi;
	if (after > 0)
	{
		res = ft_strcat(res, ".");
		i = ft_strlen(tempf);
		while (i < after)
		{
			res = ft_strcat(res, "0");
			i++;
		}
		res = ft_strcat(res, tempf);
	}
	if (n < 0)
	{
		res = pt_strmove(res, tempf, 1);
		res[0] = '-';
	}
	tempi = ft_strcpy(tempi, res);
	return (tempi);
}

static void		prep(long *i, long double *f, double n)
{
	if (n < 0)
	{
		*i = (long)n * -1;
		*f = (n * -1) - (long double)*i;
	}
	else
	{
		*i = (long)n;
		*f = n - (long double)*i;
	}
}

static void		roundnumber_even(char *tempf, long *i, long double f, int after)
{
	long		j;

	if (after > 0)
	{
		f = f * ft_inttopower(10, after + 1);
		j = (int)f % 10;
		f /= 10;
		if (j >= 6)
			f++;
		tempf = (pt_itoa(f, tempf));
	}
	else if (after == 0)
	{
		f = f * ft_inttopower(10, after + 1);
		j = (int)f % 10;
		f /= 10;
		if (j >= 6)
			*i += 1;
	}
}

static void		roundnumber(char *tempf, long *i, long double f, int after)
{
	long		j;

	if (after > 0)
	{
		f = f * ft_inttopower(10, after + 1);
		j = (int)f % 10;
		f /= 10;
		if (j >= 5)
			f++;
		tempf = (pt_itoa(f, tempf));
	}
	else if (after == 0)
	{
		f = f * ft_inttopower(10, after + 1);
		j = (int)f % 10;
		f /= 10;
		if (j >= 5)
			*i += 1;
	}
}

char			*pt_ftoa(double n, int after, char *tempi, char *tempf)
{
	long		i;
	long double	f;

	prep(&i, &f, n);
	if (ft_iseven(i % 10))
		roundnumber_even(tempf, &i, f, after);
	else
		roundnumber(tempf, &i, f, after);
	tempi = pt_itoa_l(i, tempi);
	tempi = strfinal(tempi, tempf, after, n);
	return (tempi);
}
