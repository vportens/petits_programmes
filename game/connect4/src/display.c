#include "connect4.h"
#include "libft.h"

void	display_board(t_game *game)
{
	int	i = 0;
	int	j = 0;

	if (game->columns > 300 || game->lines > 300)
		return (ft_putstr_fd("Board too big to be displayed\n", 1));
	while (i < game->lines)
	{
		j = 0;
		while (j < game->columns)
		{
			if (game->board[i][j] == AI)
				ft_putstr_fd("\x1b[1;31mO \x1b[0m", 1);
			else if (game->board[i][j] == PLAYER)
				ft_putstr_fd("\x1b[1;33mO \x1b[0m", 1);
			else
				ft_putstr_fd("\x1b[1mO \x1b[0m", 1);
			j++;
		}
		ft_putstr_fd("\n", 1);
		i++;
	}
	display_numbers(game);
}

void	clear_screen(void)
{
	//clear screen
	ft_putstr_fd("\x1b[2J", 1);
	//move to row 1 column 1
	ft_putstr_fd("\x1b[1;1H", 1);
}

void	display_numbers(t_game *game)
{
	int	i = 0;

	i = 0;
	if (game->columns > 10)
		return ;
	while (i < game->columns - 1)
	{
		ft_putstr_fd("__", 1);
		i++;
	}
	ft_putstr_fd("_\n", 1);
	i = 0;
	while (i < game->columns)
	{
		ft_putnbr_fd(i, 1);
		ft_putchar_fd(' ', 1);
		i++;
	}
	ft_putstr_fd("\n\n", 1);
}

void	display_winner(t_game *game)
{
	if (game->game_over == PLAYER)
		ft_putstr_fd("\x1b[32mPlayer wins !\x1b[0m\n", 1);
	else if (game->game_over == AI)
		ft_putstr_fd("\x1b[31mAI wins !\x1b[0m\n", 1);
	else
		ft_putstr_fd("\x1b[33mDraw !\x1b[0m\n", 1);
}
