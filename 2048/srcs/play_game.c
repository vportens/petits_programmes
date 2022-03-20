/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marnaudy <marnaudy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/19 16:04:59 by marnaudy          #+#    #+#             */
/*   Updated: 2022/03/20 18:04:20 by marnaudy         ###   ########.fr       */
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

static int	player_continues(int score, char *name)
{
	int	c;

	(void) name;
	while (1)
	{
		if (LINES > 2 && COLS > 30)
		{
			if (clear() == ERR
				|| move(LINES / 2 - 1, COLS / 2 - 13) == ERR
				|| addstr("Congratulations you won !") == ERR
				|| move(LINES / 2, COLS / 2 - 8) == ERR
				|| printw("Score = %i", score) == ERR
				|| move(LINES / 2 + 1, COLS / 2 - 15) == ERR
				|| addstr("Do you wish to continue (y/n)") == ERR)
				exit_ncurses(1);
		}
		c = getch();
		if (c == ERR)
			exit_ncurses(1);
		switch (c)
		{
		case 'y':
			return (1);
		case 'n':
			return (0);
		}
	}
}

static int	win_value()
{
	int	win_value;
	
	win_value = WIN_VALUE;
	if (win_value <= 0)
		return (0);
	if (win_value == 1)
		return (WIN_VALUE);
	while (win_value)
	{
		if (win_value % 2)
			return (0);
		if (win_value == 2)
			return (WIN_VALUE);
		win_value /= 2;
	}
	return (WIN_VALUE);
}

int	play_game(int size, char *name)
{
	int	board[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
	int	score;
	int	max_tile;

	score = 0;
	max_tile = 0;
	srand(time(NULL));
	add_number(board, size);
	add_number(board, size);
	while (1)
	{
		if (max_tile < win_value() && get_max(board, size) >= win_value())
		{
			if (player_continues(score, name) == 0)
				break ;
		}
		max_tile = get_max(board, size);
		if (play_round(board, size, &score))
			return (score);
		add_number(board, size);
		if (is_game_over(board, size))
			return (game_over_screen(score, name));
	}
	return (score);
}
