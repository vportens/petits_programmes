#include "connect4.h"
#include "libft.h"
#include "stdlib.h"

int	main(int ac, char *av[])
{
	t_game	game;

	ft_memset(&game, 0, sizeof(game));
	if (init_game(&game, ac, av) == ERROR)
		return (1);
	clear_screen();
	display_board(&game);
	while (!game.game_over && !board_full(&game))
	{
		if (game.begin % 2)
		{
			ft_putstr_fd("Player's turn\n", 1);
			if (get_move(&game) <= 0)
				return (partial_destroy_board(&game, game.lines), 1);
			make_move(&game, game.player_answer, PLAYER);
			clear_screen();
		}
		else
		{
			clear_screen();
			make_move(&game, ai_pseudo_smart_move(&game), AI);
		}
		display_board(&game);
		game.game_over = check_winner(&game, VERBOSE);
		game.begin++;
	}
	display_winner(&game);
	partial_destroy_board(&game, game.lines);
	return (0);
}
