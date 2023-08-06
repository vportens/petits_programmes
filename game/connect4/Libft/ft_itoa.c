/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:52:49 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/08 17:34:22 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_lennb(long nbr)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		i++;
		nbr *= -1;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

static char	*ft_createtab(long nbr)
{
	char	*tab;
	int		len;

	len = 0;
	tab = NULL;
	len = ft_lennb(nbr);
	tab = (char *)malloc((len + 1) * sizeof(char));
	if (! tab)
		return (NULL);
	if (nbr < 0)
		tab[0] = '-';
	tab[len] = '\0';
	return (tab);
}

static char	*ft_catchzero(void)
{
	char	*tab;

	tab = NULL;
	tab = (char *)malloc(2 * sizeof(char));
	if (! tab)
		return (NULL);
	tab[0] = '0';
	tab[1] = '\0';
	return (tab);
}

char	*ft_itoa(int n)
{
	char	*tab;
	long	nbr;
	int		i;

	tab = NULL;
	nbr = n;
	i = 0;
	if (nbr == 0)
		return (ft_catchzero());
	tab = ft_createtab(nbr);
	if (! tab)
		return (NULL);
	if (nbr < 0)
		nbr *= -1;
	while (nbr > 0)
	{
		tab[ft_lennb(n) - 1 - i] = nbr % 10 + 48;
		nbr /= 10;
		i++;
	}
	return (tab);
}
