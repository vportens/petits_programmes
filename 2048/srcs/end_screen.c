#include <ncurses.h>
#include "game.h"

int	game_over_screen(int score, char *name)
{
	int	c;

	(void) name;
	while (1)
	{
		if (LINES > 2 && COLS > 26)
		{
			if (clear() == ERR
				|| move(LINES / 2 - 1, COLS / 2 - 5) == ERR
				|| addstr("Gameover") == ERR
				|| move(LINES / 2, COLS / 2 - 8) == ERR
				|| printw("Score = %i", score) == ERR
				|| move(LINES - 1, COLS / 2 - 13) == ERR
				|| addstr("Press ENTER to continue") == ERR)
				exit_ncurses(1);
		}
		c = getch();
		if (c == ERR)
			exit_ncurses(1);
		if (c == 10)
			return (score);
	}
}
