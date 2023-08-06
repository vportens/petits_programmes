#include "connect4.h"
#include "libft.h"

int	check_position_row_unbroken(t_game *game, int i, int j, int who)
{
	int	in_a_row = 0;

	while (j < game->columns)
	{
		if (game->board[i][j] == who)
			in_a_row++;
		else
			break ;
		j++;
	}
	return (in_a_row);
}

int	check_position_column_unbroken(t_game *game, int i, int j, int who)
{
	int	in_a_row = 0;

	while (i < game->lines)
	{
		if (game->board[i][j] == who)
			in_a_row++;
		else
			break ;
		i++;
	}
	return (in_a_row);
}

int	check_position_rdiag_unbroken(t_game *game, int i, int j, int who)
{
	int	in_a_row = 0;

	while (i < game->lines && j < game->columns)
	{
		if (game->board[i][j] == who)
			in_a_row++;
		else
			break ;
		i++;
		j++;
	}
	return (in_a_row);
}

int	check_position_ldiag_unbroken(t_game *game, int i, int j, int who)
{
	int	in_a_row = 0;

	while (i < game->lines && j >= 0)
	{
		if (game->board[i][j] == who)
			in_a_row++;
		else
			break ;
		i++;
		j--;
	}
	return (in_a_row);
}

int	position_align_score_unbroken(t_game *game, int i, int j, int who, int verbose)
{
	int	(*check_fx[4])();
	int	index = 0;
	int	max = 0;
	int	current;

	check_fx[0] = check_position_row_unbroken;
	check_fx[1] = check_position_column_unbroken;
	check_fx[2] = check_position_rdiag_unbroken;
	check_fx[3] = check_position_ldiag_unbroken;

	while (index < 4)
	{
		current = check_fx[index](game, i, j, who, verbose);
		max = max < current ? current : max;
		index++;
	}
	return (max);
}

int	get_align_score(t_game *game, int who)
{
	int	i = 0;
	int	j = 0;
	int	total_score = 0;
	int	pos_score;

	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->board[i][j] != 0)
			{
				pos_score = position_align_score_unbroken(game, i, j, who, SILENT);
				total_score += (pos_score * pos_score);
			}
			j++;
		}
		i++;
	}
	return (total_score);
}
