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

	while (i < size)
	{
	
		j = 0;
		while (j < size)
		{
			nbr = ft_itoa(map[i][j]);
			if (nbr == NULL)
				return ;
			printf("nbr: %s\n", nbr);
			move(len_halfcase_x + len_case_x * i, len_halfcase_y + len_case_y * j);
			printw(nbr, (len_halfcase_x + len_case_x * i) * 2, (len_halfcase_y + len_case_y * j) * 2);
			
	//	addch(map[i][j] + '0');
			j++;
			free(nbr);
		}
		i++;
		
	}
}

int main()
{
	int size = 4;
	int map[4][4] = {{1,2,3,4}, {5,6,7,8}, {11,22,33,44}, {999,888,777,555}};
	
	initscr();
	print_game(map, size);
	refresh();
	getch();
	endwin();
	return (0);
}
