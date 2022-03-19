#include <ncurses.h>
#include <stdlib.h>

#include "game.h"




void	print_game(int map[4][4], int size)
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
			attron(A_BOLD | A_UNDERLINE);
			move(len_halfcase_x + len_case_x * i, len_halfcase_y + len_case_y * j);
			printw(nbr, (len_halfcase_x + len_case_x * i) * 2, (len_halfcase_y + len_case_y * j) * 2);
	//	addch(map[i][j] + '0');
			j++;
			free(nbr);
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
	int map[4][4] = {{1,2,3,4}, {5,6,7,8}, {12,23,34,45}, {999,888,777,555}};
	char c;	


	initscr();

	start_color();	
	init_pair(1, COLOR_RED, COLOR_BLACK);
	attron(COLOR_PAIR(1));
	print_game(map, size);
	attroff(COLOR_PAIR(1));
	refresh();
	while (1)
	{
		c = getch();
		print_game(map, size);
		refresh();
		if (c == 'q')
			break;

	}
	endwin();



	return (0);
}
