#include <ncurses.h>
#include <stdlib.h>

#include "game.h"




void	print_game(int map[5][5], int size, int score)
{
	if (LINES < 11 || COLS < 50)
		return ;
	print_map(size);
	
	int len_halfcase_y;
	int len_halfcase_x;

	len_halfcase_y = (COLS -1) / size / 2;
	len_halfcase_x = (LINES-1) / size / 2;

	int i = 0;
	int j = 0;

	if (COLS < 26 * size + 1|| LINES < 6 * size + 1)
	{
	while (i < size)
	{
	
		j = 0;
		while (j < size)
		{
			if (map[i][j] == 0)
				j++;
			else
			{
				if (attron(A_BOLD | A_UNDERLINE) == ERR
					|| move(len_halfcase_x + (LINES-1) * i / size, len_halfcase_y + (COLS -1) * j / size) == ERR
					|| printw("%i", map[i][j], (len_halfcase_x + (LINES-1) * i / size) * 2, (len_halfcase_y + (COLS -1) * j / size) * 2) == ERR
					|| attroff(A_BOLD | A_UNDERLINE) == ERR)
					exit_ncurses(1);
		//	addch(map[i][j] + '0');
				j++;
			}
		}
		i++;
		
	}
	}
	else
		print_ascii_num(size, map);
	print_score(score);
}
