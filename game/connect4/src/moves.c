#include "connect4.h"
#include "libft.h"

void	make_move(t_game *game, int move, int who)
{
	int	last_empty_line = 0;

	while (last_empty_line < game->lines
			&& game->board[last_empty_line][move] == 0)
		last_empty_line++;
	if (who == PLAYER)
		game->board[--last_empty_line][move] = PLAYER;
	else
		game->board[--last_empty_line][move] = AI;
	return ;
}

void	remove_move(t_game *game, int move)
{
	int	last_empty_line = 0;

	while (game->board[last_empty_line][move] == 0)
		last_empty_line++;
	game->board[last_empty_line][move] = 0;
	return ;
}

int	get_move(t_game *game)
{
	char	*input = NULL;
	int		read_res = 0;
	int		valid_input = 0;

	while (!valid_input)
	{
		ft_putstr_fd("Enter the column you wish to put a token in :\n", 1);
		read_res = sget_next_line(&input, 0);
		if (read_res == -1)
			return (ft_putstr_fd("Read error\n", 2), ERROR);
		if (read_res == -2)
			return (ft_putstr_fd("Malloc error\n", 2), ERROR);
		if (read_res == 0)
			return (ft_putstr_fd("Scared of losing quitter ?\n", 1), INPUT_EOF);
		valid_input = check_player_input(game, input);
		free(input);
	}
	return (1);
}
