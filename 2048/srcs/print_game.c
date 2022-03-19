#include <ncurses.h>
#include <stdlib.h>

#include "game.h"




void	print_game(int map[5][5], int size)
{
	print_map(size);
	
	int len_case_y;		
	int len_case_x;		
	int len_halfcase_y;
	int len_halfcase_x;

	len_case_y = (COLS -1) / size;
	len_halfcase_y = len_case_y / 2;

	len_case_x = (LINES-1) / size;
	len_halfcase_x = len_case_x / 2;

	int i = 0;
	int j = 0;

	char *nbr;

	if (COLS < 26 * size + 1|| LINES < 6 * size + 1)
	{
	while (i < size)
	{
	
		j = 0;
		while (j < size)
		{
			nbr = ft_itoa(map[i][j]);


			if (nbr == NULL)
				return ;
			if (nbr[0] == '0')
			{
				free(nbr);
				j++;
			}
			else
			{
				attron(A_BOLD | A_UNDERLINE);
				move(len_halfcase_x + len_case_x * i, len_halfcase_y + len_case_y * j);
				printw(nbr, (len_halfcase_x + len_case_x * i) * 2, (len_halfcase_y + len_case_y * j) * 2);
				attroff(A_BOLD | A_UNDERLINE);
		//	addch(map[i][j] + '0');
				j++;
				free(nbr);
			}
		}
		i++;
		
	}
	}
	else
		print_ascii_num(size, map);
}

int main()
{
	int size = 4;
	int	score;


	initscr();
	keypad(stdscr, TRUE);
	cbreak();
	noecho();
	curs_set(0);
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	score = play_game(size);
	attroff(COLOR_PAIR(1));
	endwin();
	printf("Your score is %d\n", score);
	return (0);
}
