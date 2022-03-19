/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 15:32:01 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/19 17:23:00 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

static void	swap(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	move_left(int board[5][5], int size)
{
	int	i;
	int	empty;
	int	full;
	int	ret;

	ret = merge_left(board, size);
	i = 0;
	while (i < size)
	{
		empty = 0;
		while (empty < size - 1)
		{
			if (board[i][empty] == 0)
			{
				full = empty + 1;
				while (board[i][full] == 0 && full < size)
					full++;
				if (full < size)
				{
					swap(&board[i][empty], &board[i][full]);
					ret = 0;
				}
			}	
			empty++;
		}
		i++;
	}
	return (ret);
}

int	move_right(int board[5][5], int size)
{
	int	i;
	int	empty;
	int	full;
	int	ret;

	ret = merge_right(board, size);
	i = 0;
	while (i < size)
	{
		empty = size - 1;
		while (empty > 0)
		{
			if (board[i][empty] == 0)
			{
				full = empty - 1;
				while (board[i][full] == 0 && full >= 0)
					full--;
				if (full >= 0)
				{
					ret = 0;
					swap(&board[i][empty], &board[i][full]);
				}
			}	
			empty--;
		}
		i++;
	}
	return (ret);
}

int	move_up(int board[5][5], int size)
{
	int	i;
	int	empty;
	int	full;
	int	ret;

	ret = merge_up(board, size);
	i = 0;
	while (i < size)
	{
		empty = 0;
		while (empty < size - 1)
		{
			if (board[empty][i] == 0)
			{
				full = empty + 1;
				while (board[full][i] == 0 && full < size)
					full++;
				if (full < size)
				{
					ret = 0;
					swap(&board[empty][i], &board[full][i]);
				}
			}	
			empty++;
		}
		i++;
	}
	return (ret);
}

int	move_down(int board[5][5], int size)
{
	int	i;
	int	empty;
	int	full;
	int	ret;

	ret = merge_down(board, size);
	i = 0;
	while (i < size)
	{
		empty = size - 1;
		while (empty > 0)
		{
			if (board[empty][i] == 0)
			{
				full = empty - 1;
				while (board[full][i] == 0 && full >= 0)
					full--;
				if (full >= 0)
				{
					ret = 0;
					swap(&board[empty][i], &board[full][i]);
				}
			}	
			empty--;
		}
		i++;
	}
	return (ret);
}
