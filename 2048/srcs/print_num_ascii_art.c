#include <ncurses.h>
#include <stdlib.h>
#include "game.h"


int ft_strlen(char *nbr)
{
	int i = 0;
	while (nbr[i])
		i++;
	return (i);
}

/*
	999	
    9 9
    999
	  9
	  9
*/
void	print_nine(int centre_x, int centre_y)
{
		move(centre_x -2, centre_y - 1);
		addch('9');
		move(centre_x -2, centre_y);
		addch('9');
		move(centre_x -2, centre_y + 1);
		addch('9');
		move(centre_x -1, centre_y - 1);
		addch('9');
		move(centre_x -1, centre_y + 1);
		addch('9');
		move(centre_x , centre_y - 1);
		addch('9');
		move(centre_x , centre_y);
		addch('9');
		move(centre_x , centre_y + 1);
		addch('9');
		move(centre_x + 1, centre_y + 1);
		addch('9');
		move(centre_x + 2, centre_y + 1);
		addch('9');

}

/*
	888
	8 8
	888
	8 8
	888
*/

void	print_height(int centre_x, int centre_y)
{
		move(centre_x -2, centre_y - 1);
		addch('8');
		move(centre_x -2, centre_y);
		addch('8');
		move(centre_x -2, centre_y + 1);
		addch('8');
		move(centre_x -1, centre_y - 1);
		addch('8');
		move(centre_x -1, centre_y + 1);
		addch('8');
		move(centre_x, centre_y - 1);
		addch('8');
		move(centre_x , centre_y);
		addch('8');
		move(centre_x , centre_y + 1);
		addch('8');
		move(centre_x +1, centre_y - 1);
		addch('8');
		move(centre_x +1, centre_y + 1);
		addch('8');
		move(centre_x +2, centre_y - 1);
		addch('8');
		move(centre_x +2, centre_y);
		addch('8');
		move(centre_x +2, centre_y + 1);
		addch('8');
	

}

/*
	777
	  7
	  7
	  7
	  7
*/

void	print_seven(int centre_x, int centre_y)
{
		move(centre_x -2, centre_y - 1);
		addch('7');
		move(centre_x - 2, centre_y);
		addch('7');
		move(centre_x - 2, centre_y + 1);
		addch('7');
		move(centre_x -1, centre_y + 1);
		addch('7');
		move(centre_x , centre_y + 1);
		addch('7');
		move(centre_x + 1, centre_y + 1);
		addch('7');
		move(centre_x + 2, centre_y + 1);
		addch('7');

}

/*
	6
	6
	666
	6 6
	666
*/

void	print_six(int centre_x, int centre_y)
{
		move(centre_x -2, centre_y - 1);
		addch('6');
		move(centre_x -1, centre_y - 1);
		addch('6');
		move(centre_x , centre_y - 1);
		addch('6');
		move(centre_x , centre_y);
		addch('6');
		move(centre_x , centre_y + 1);
		addch('6');
		move(centre_x + 1, centre_y - 1);
		addch('6');
		move(centre_x + 1, centre_y + 1);
		addch('6');
		move(centre_x + 2, centre_y - 1);
		addch('6');
		move(centre_x + 2, centre_y);
		addch('6');
		move(centre_x + 2, centre_y + 1);
		addch('6');

}

/*
	555
	5
	555
	  5
	555
*/

void	print_five(int centre_x, int centre_y)
{
		move(centre_x - 2, centre_y - 1);
		addch('5');
		move(centre_x - 2, centre_y);
		addch('5');
		move(centre_x -2, centre_y + 1);
		addch('5');
		move(centre_x -1, centre_y - 1);
		addch('5');
		move(centre_x , centre_y - 1);
		addch('5');
		move(centre_x , centre_y);
		addch('5');
		move(centre_x , centre_y + 1);
		addch('5');
		move(centre_x + 1, centre_y +1);
		addch('5');
		move(centre_x + 2, centre_y - 1);
		addch('5');
		move(centre_x + 2, centre_y);
		addch('5');
		move(centre_x +2, centre_y + 1);
		addch('5');

}

/*
	4 4
	4 4
	444
	  4
	  4
*/
void	print_four(int centre_x, int centre_y)
{
		move(centre_x -2, centre_y - 1);
		addch('4');
		move(centre_x -2, centre_y + 1);
		addch('4');
		move(centre_x -1, centre_y - 1);
		addch('4');
		move(centre_x -1, centre_y + 1);
		addch('4');
		move(centre_x , centre_y - 1);
		addch('4');
		move(centre_x , centre_y);
		addch('4');
		move(centre_x , centre_y + 1);
		addch('4');
		move(centre_x + 1, centre_y + 1);
		addch('4');
		move(centre_x + 2, centre_y + 1);
		addch('4');


}

/*
	333
	  3
	 33
	  3
	333 
*/

void	print_three(int centre_x, int centre_y)
{
		move(centre_x - 2, centre_y - 1);
		addch('3');
		move(centre_x - 2, centre_y);
		addch('3');
		move(centre_x - 2, centre_y + 1);
		addch('3');
		move(centre_x -1, centre_y + 1);
		addch('3');
		move(centre_x , centre_y);
		addch('3');
		move(centre_x , centre_y + 1);
		addch('3');
		move(centre_x + 1, centre_y + 1);
		addch('3');
		move(centre_x + 2, centre_y - 1);
		addch('3');
		move(centre_x + 2, centre_y);
		addch('3');
		move(centre_x + 2, centre_y + 1);
		addch('3');
	
}

/*
	222
	  2
	222
	2
	222
*/

void	print_two(int centre_x, int centre_y)
{
		move(centre_x -2 , centre_y - 1);
		addch('2');
		move(centre_x -2, centre_y);
		addch('2');
		move(centre_x -2, centre_y + 1);
		addch('2');
		move(centre_x -1, centre_y + 1);
		addch('2');
		move(centre_x , centre_y - 1);
		addch('2');
		move(centre_x , centre_y);
		addch('2');
		move(centre_x , centre_y + 1);
		addch('2');
		move(centre_x + 1, centre_y - 1);
		addch('2');
		move(centre_x +2 , centre_y - 1);
		addch('2');
		move(centre_x +2, centre_y);
		addch('2');
		move(centre_x +2, centre_y + 1);
		addch('2');
}

/*
	1
	1
	1
	1
	1
*/

void	print_one(int centre_x, int centre_y)
{
		move(centre_x -2, centre_y);
		addch('1');
		move(centre_x -1, centre_y);
		addch('1');
		move(centre_x , centre_y);
		addch('1');
		move(centre_x +1, centre_y);
		addch('1');
		move(centre_x +2, centre_y);
		addch('1');

}

void print_nbr(char nbr, int centre_x, int centre_y)
{
	if (nbr == '1')
		return (print_one(centre_x, centre_y));
	else if (nbr == '2')
		return (print_two(centre_x, centre_y));
	else if (nbr == '3')
		return (print_three(centre_x, centre_y));
	else if (nbr == '4')
		return (print_four(centre_x, centre_y));
	else if (nbr == '5')
		return (print_five(centre_x, centre_y));
	else if (nbr == '6')
		return (print_six(centre_x, centre_y));
	else if (nbr == '7')
		return (print_seven(centre_x, centre_y));
	else if (nbr == '8')
		return (print_height(centre_x, centre_y));
	else if(nbr == '9')
		return (print_nine(centre_x, centre_y));

}


void	print_ascii_num(int size, int map[5][5])
{
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
	int len_nbr;
	int n = 0;
	char *nbr;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			start_color();	
			if (map[i][j] < 16)
				init_pair(1, COLOR_RED, COLOR_BLUE);
			else if (map[i][j] < 128)
				init_pair(1, COLOR_MAGENTA, COLOR_BLUE);
			attron(COLOR_PAIR(1));
			nbr = ft_itoa(map[i][j]);
			len_nbr = ft_strlen(nbr);
			n = 0;
			while (n < len_nbr)
			{
				print_nbr(nbr[n], len_halfcase_x + len_case_x * i, (len_halfcase_y + len_case_y * j) + ((-len_nbr /2 + n) * 5));
				n++;
			}
			
			attroff(COLOR_PAIR(1));
			j++;

		}
		i++;

	}
}
