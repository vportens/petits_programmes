#include "game.h"
#include <ncurses.h>

static void	init_ncurses(void)
{
	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
}

static void	exit_ncurses(void)
{
	attroff(COLOR_PAIR(1));
	endwin();
}

static void display_main_menu(void)
{
	clear();
	move(LINES / 2 - 2, COLS / 2 - 2);
	addstr("2048");
	move(LINES / 2 - 1, COLS / 2 - 10);
	addstr("Press 1 to play 4x4");
	move(LINES / 2, COLS / 2 - 10);
	addstr("Press 2 to play 5x5");
	move(LINES / 2 + 1, COLS / 2 - 13);
	addstr("Press 3 to see highscores");
	move(LINES / 2 + 2, COLS / 2 - 8);
	addstr("Press 4 to exit");
}

void	main_menu(void)
{
	int	c;

	while (1)
	{
		display_main_menu();
		c = getch();
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
			return ;
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
	exit_ncurses();
	return (0);
}
