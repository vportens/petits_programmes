/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_round.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:21:35 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/19 23:43:20 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <ncurses.h>

int	play_round(int board[5][5], int size, int *score)
{
	int	c;

	while (1)
	{
		clear();
		print_game(board, size);
		print_score(score);
		refresh();
		c = getch();
		switch (c)
		{
			case KEY_UP:
				if (move_up(board, size, score))
					break ;
				else
					return (0);
			case KEY_DOWN:
				if (move_down(board, size, score))
					break ;
				else
					return (0);
			case KEY_LEFT:
				if (move_left(board, size, score))
					break ;
				else
					return (0);
			case KEY_RIGHT:
				if (move_right(board, size, score))
					break ;
				else
					return (0);
			case 27:
				return (1);
		}
	}
}
