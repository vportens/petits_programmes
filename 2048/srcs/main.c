#include "game.h"
#include <ncurses.h>

static void	init_ncurses(void)
{
	if (initscr() == NULL
		|| keypad(stdscr, TRUE) == ERR
		|| cbreak() == ERR
		|| noecho() == ERR
		|| curs_set(0) == ERR
		|| start_color() == ERR
		|| init_pair(1, COLOR_RED, COLOR_BLUE) == ERR
		|| init_pair(2, COLOR_MAGENTA, COLOR_BLUE) == ERR
		|| init_pair(3, COLOR_YELLOW, COLOR_CYAN) == ERR
		|| init_pair(4, COLOR_YELLOW, COLOR_CYAN) == ERR
		|| init_pair(5, COLOR_YELLOW, COLOR_YELLOW) == ERR)
		exit_ncurses(1);
}

void	exit_ncurses(int code)
{
	standend();
	endwin();
	exit_curses(code);
}

static void display_main_menu(void)
{
	if (clear() == ERR
		|| move(LINES / 2 - 2, COLS / 2 - 2) == ERR
		|| addstr("2048") == ERR
		|| move(LINES / 2 - 1, COLS / 2 - 10) == ERR
		|| addstr("Press 1 to play 4x4") == ERR
		|| move(LINES / 2, COLS / 2 - 10) == ERR
		|| addstr("Press 2 to play 5x5") == ERR
		|| move(LINES / 2 + 1, COLS / 2 - 13) == ERR
		|| addstr("Press 3 to see highscores") == ERR
		|| move(LINES / 2 + 2, COLS / 2 - 8) == ERR
		|| addstr("Press 4 to exit") == ERR
		|| refresh() == ERR)
		exit_ncurses(1);
}

void	main_menu(void)
{
	int	c;

	while (1)
	{
		display_main_menu();
		c = getch();
		if (c == ERR)
			exit_ncurses(1);
		switch (c)
		{
			case '1':
			{
				play_game(4);
				break ;
			}
			case '2':
			{
				play_game(5);
				break ;
			}
			case '3':
			{
				score_page("score.txt");
				break ;
			}
			case '4':
				return ;
			case 27:
				return ;
		}
	}
}

int main()
{
	init_ncurses();
	main_menu();
	exit_ncurses(0);
}
