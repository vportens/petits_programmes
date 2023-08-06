#include "connect4.h"

int	board_full(t_game *game)
{
	int	i = 0;
	int	j = 0;

	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->board[i][j] == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
