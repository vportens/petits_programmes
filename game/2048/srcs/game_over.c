/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 18:48:05 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/19 18:54:43 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static int	row_merge_possible(int board[5][5], int size, int n)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (board[n][i] == board[n][i + 1])
			return (1);
		i++;
	}
	return (0);
}

static int	col_merge_possible(int board[5][5], int size, int n)
{
	int	i;

	i = 0;
	while (i < size - 1)
	{
		if (board[i][n] == board[i + 1][n])
			return (1);
		i++;
	}
	return (0);
}

int	is_game_over(int board[5][5], int size)
{
	int	i;

	if (!is_full(board, size))
		return (0);
	i = 0;
	while (i < size)
	{
		if (row_merge_possible(board, size, i) || col_merge_possible(board, size, i))
			return (0);
		i++;
	}
	return (1);
}
