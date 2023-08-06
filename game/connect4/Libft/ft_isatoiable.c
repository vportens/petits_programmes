/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isatoiable.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 14:27:50 by fle-blay          #+#    #+#             */
/*   Updated: 2022/02/12 14:28:20 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_atoiable(char **tab)
{
	int	i;
	int	j;
	int	sign;

	i = 0;
	while (tab[i])
	{
		sign = 0;
		j = 0;
		if (ft_strlen(tab[i]) == 1 && (tab[i][0] == '-' || tab[i][0] == '+'))
			return (0);
		while (tab[i][j])
		{
			if (!ft_isdigit(tab[i][j]) && tab[i][j] != '-' && tab[i][j] != '+')
				return (0);
			if (tab[i][j] == '-' || tab[i][j] == '+')
				sign++;
			j++;
		}
		if (sign > 1)
			return (0);
		i++;
	}
	return (1);
}
