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
					|| move(len_halfcase_x + len_case_x * i, len_halfcase_y + len_case_y * j) == ERR
					|| printw("%i", map[i][j], (len_halfcase_x + len_case_x * i) * 2, (len_halfcase_y + len_case_y * j) * 2) == ERR
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
}
