/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_tile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:53:43 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/19 17:48:56 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	is_full(int board[5][5], int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	add_number(int board[5][5], int size)
{
	int i;
	int	j;

	if (is_full(board, size))
		return (-1);
	while (1)
	{
		i = rand() % size;
		j = rand() % size;
		if (board[i][j] == 0)
		{
			if (rand() % 3)
				board[i][j] = 2;
			else
				board[i][j] = 4;
			return (0);
		}
	}
}
