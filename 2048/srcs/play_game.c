/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:04:59 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/20 11:42:31 by marnaudy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"
#include <stdlib.h>
#include <time.h>
#include <ncurses.h>

static int	get_max(int board[5][5], int size)
{
	int	i;
	int	j;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (board[i][j] > max)
				max = board[i][j];
			j++;
		}
		i++;
	}
	return (max);
}

static int	player_continues(void)
{
	int	c;

	clear();
	move(LINES / 2, COLS / 2 - 13);
	addstr("Congratulations you won !");
	move(LINES / 2 + 1, COLS / 2 - 15);
	addstr("Do you wish to continue (y/n)");
	while (1)
	{
		c = getch();
		switch (c)
		{
		case 'y':
			return (1);
		case 'n':
			return (0);
		}
	}
}

int	play_game(int size)
{
	int	board[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
	int	score;
	int	max_tile;

	score = 0;
	srand(time(NULL));
	add_number(board, size);
	while (1)
	{
		add_number(board, size);
		if (is_game_over(board, size))
			break ;
		max_tile = get_max(board, size);
		if (play_round(board, size, &score))
			break ;
		if (max_tile < WIN_VALUE && get_max(board, size) >= WIN_VALUE)
		{
			if (player_continues() == 0)
				break ;
		}
	}
	return (score);
}
