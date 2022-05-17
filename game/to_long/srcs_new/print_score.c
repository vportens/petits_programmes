/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_score.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 18:29:38 by laclide           #+#    #+#             */
/*   Updated: 2021/08/16 18:30:53 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	remove_score(t_long *stc)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = stc->nbr_move - 1;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		i++;
	}
	while (i >= 0)
	{
		write(1, "\b", 1);
		i--;
	}
}

void	print_final_score(t_long *stc)
{
	int	i;

	i = 16;
	remove_score(stc);
	while (i > 0)
	{
		write(1, "\b", 1);
		i--;
	}
	write(1, "final score ", 12);
	print_score(stc);
}

void	print_score(t_long *stc)
{
	int		i;
	int		tmp;
	char	nbr;

	i = 1;
	tmp = stc->nbr_move;
	while (tmp > 9)
	{
		tmp = tmp / 10;
		i = i * 10;
	}
	tmp = stc->nbr_move;
	while (i > 9)
	{
		nbr = tmp / i + 48;
		tmp = tmp % i;
		i = i / 10;
		write(1, &nbr, 1);
	}
	nbr = tmp / i + 48;
	write(1, &nbr, 1);
}
