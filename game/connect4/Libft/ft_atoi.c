/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 17:47:26 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/07 12:55:23 by fred             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	if (c == '\f' || c == '\t' || c == '\n' || c == '\r' || c == '\v' \
		|| c == ' ')
		return (1);
	return (0);
}

int	ft_atoi(const char *nptr)
{
	int				i;
	long long int	nbr;
	int				sign;

	i = 0;
	sign = 1;
	nbr = 0;
	while (ft_isspace(nptr[i]))
		i++;
	if (! ft_isdigit(nptr[i]))
	{
		if (nptr[i] != '-' && nptr[i] != '+')
			return (nbr);
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (ft_isdigit(nptr[i]))
	{
		nbr *= 10;
		nbr += nptr[i] - 48;
		i++;
	}
	return (sign * nbr);
}
