#include "connect4.h"
#include "libft.h"

int	check_ai_input(t_game *game, int input)
{
	if (input > game->columns - 1 || input < 0)
		return (0);
	if (game->board[0][input] != 0)
		return (0);
	return (1);
}

int	check_player_input(t_game *game, char *input)
{
	int	error = 0;

	if (!input)
		return (0);
	game->player_answer = ft_satoi(input, &error);
	if (error)
		return (ft_putstr_fd("wrong format or overflow attempt in answer\n", 1), 0);
	if (game->player_answer > game->columns - 1 || game->player_answer < 0)
		return (ft_putstr_fd("Out of bound answer\n", 1), 0);
	if (game->board[0][game->player_answer] != 0)
		return (ft_putstr_fd("Column is already full!\n", 2), 0);
	return (1);
}

int	check_position_row(t_game *game, int i, int j, int who, int verbose)
{
	int	max = 0;
	int	in_a_row = 0;

	while (j < game->columns)
	{
		if (game->board[i][j] == who)
		{
			in_a_row++;
			max = max < in_a_row ? in_a_row : max;
		}
		else
			in_a_row = 0;
		j++;
	}
	if (max >= 4 && verbose)
			ft_putstr_fd("Line win\n", 1);
	return (max);
}

int	check_position_column(t_game *game, int i, int j, int who, int verbose)
{
	int	max = 0;
	int	in_a_row = 0;

	while (i < game->lines)
	{
		if (game->board[i][j] == who)
		{
			in_a_row++;
			max = max < in_a_row ? in_a_row : max;
		}
		else
			in_a_row = 0;
		i++;
	}
	if (max >= 4 && verbose)
			ft_putstr_fd("Column win\n", 1);
	return (max);
}

int	check_position_rdiag(t_game *game, int i, int j, int who, int verbose)
{
	int	max = 0;
	int	in_a_row = 0;

	while (i < game->lines && j < game->columns)
	{
		if (game->board[i][j] == who)
		{
			in_a_row++;
			max = max < in_a_row ? in_a_row : max;
		}
		else
			in_a_row = 0;
		i++;
		j++;
	}
	if (max >= 4 && verbose)
			ft_putstr_fd("Right diag win\n", 1);
	return (max);
}

int	check_position_ldiag(t_game *game, int i, int j, int who, int verbose)
{
	int	max = 0;
	int	in_a_row = 0;

	while (i < game->lines && j >= 0)
	{
		if (game->board[i][j] == who)
		{
			in_a_row++;
			max = max < in_a_row ? in_a_row : max;
		}
		else
			in_a_row = 0;
		i++;
		j--;
	}
	if (max >= 4 && verbose)
			ft_putstr_fd("Left diag win\n", 1);
	return (max);
}

int	position_align_score(t_game *game, int i, int j, int who, int verbose)
{
	int	(*check_fx[4])();
	int	index = 0;
	int	max = 0;
	int	current;

	check_fx[0] = check_position_row;
	check_fx[1] = check_position_column;
	check_fx[2] = check_position_rdiag;
	check_fx[3] = check_position_ldiag;

	while (index < 4)
	{
		current = check_fx[index](game, i, j, who, verbose);
		max = max < current ? current : max;
		index++;
	}
	return (max);
}

int	check_winner(t_game *game, int verbose)
{
	int	i = 0;
	int	j = 0;

	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->board[i][j] != 0)
			{
				if (position_align_score(game, i, j, PLAYER, verbose) >= 4)
					return (PLAYER);
				if (position_align_score(game, i, j, AI, verbose) >= 4)
					return (AI);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	get_max_align(t_game *game, int who)
{
	int	i = 0;
	int	j = 0;
	int	max = 0;
	int	current;

	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->board[i][j] != 0)
			{
				current = position_align_score(game, i, j, who, SILENT);
				max = max < current ? current : max;
			}
			j++;
		}
		i++;
	}
	return (max);
}
