#include "connect4.h"
#include "libft.h"
#include "time.h"
#include "stdlib.h"

int	get_param(t_game *game, char *arg1, char *arg2)
{
	int	error1 = 0;
	int error2 = 0;

	game->lines = ft_satoi(arg1, &error1);
	game->columns = ft_satoi(arg2, &error2);
	if (error1 || error2)
		return (ft_putstr_fd("Wrong format or overflow attempt in parameters\n", 2), ERROR);
	if (game->lines < LINE_MIN)
		return (ft_putstr_fd("Line parameter must be 6 or more\n", 2), ERROR);
	if (game->columns < COLUMN_MIN)
		return (ft_putstr_fd("Colum parameter must be 7 or more\n", 2), ERROR);
	if (game->lines > SIZEMAX)
		return (ft_putstr_fd("Out of bound line parameter\n", 2), ERROR);
	if (game->columns > SIZEMAX)
		return (ft_putstr_fd("Out of bound column parameter\n", 2), ERROR);
	return (1);
}

int	allocate_board(t_game *game)
{
	int	i = 0;

	game->board = (int **)malloc(game->lines * sizeof(int *));
	if (!game->board)
		return (ft_putstr_fd("Malloc error\n", 2), ERROR);
	while (i < game->lines)
	{
		game->board[i] = (int *)malloc(game->columns * sizeof(int));
		if (!game->board[i])
		{
			partial_destroy_board(game, i);
			return (ft_putstr_fd("Malloc error\n", 2), ERROR);
		}
		ft_memset(game->board[i], 0, game->columns * sizeof(int));
		i++;
	}
	return (1);
}

void	partial_destroy_board(t_game *game, int stop)
{
	int index = 0;

	while (index < stop)
		free(game->board[index++]);
	free(game->board);
}

int	init_game(t_game *game, int ac, char *av[])
{
	if (ac != 3)
		return (ft_putstr_fd("Wrong arg count\n", 2), ERROR);
	if (get_param(game, av[1], av[2]) == ERROR)
		return (ft_putstr_fd("Wrong game parameters\n", 2), ERROR);
	if (allocate_board(game) == ERROR)
		return (ft_putstr_fd("Error creating board\n", 2), ERROR);
	srand(time(NULL));
	game->begin = rand() % 2;
	return (1);
}
