/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   true_atoi.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 22:33:15 by viporten          #+#    #+#             */
/*   Updated: 2021/11/24 23:05:37 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	only_nbr(char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		i++;
	if (str[i] == '\0')
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

long	long_atoi(char *str)
{
	int		i;
	long	res;
	int		sign;

	i = 0;
	res = 0;
	while (str[i] == '\f' || str[i] == '\t' || str[i] == '\n' || str[i] == '\r'
		|| str[i] == '\v' || str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-')
	{
		sign = -1;
		i++;
	}
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10;
		res = res + str[i] - '0';
		i++;
	}
	res = res * sign;
	return (res);
}

int	ft_true_atoi(int *new, char *str)
{
	long	res;

	if (!only_nbr(str))
		return (0);
	res = long_atoi(str);
	if (res > 2147483647 || res < -2147483648)
		return (0);
	(*new) = (int)res;
	return (1);
}
