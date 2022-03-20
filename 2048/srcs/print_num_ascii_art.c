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
	000
	0 0
	0 0
	0 0
	000
*/

void	print_zero(int centre_x, int centre_y)
{
	if (move(centre_x -2, centre_y - 1) == ERR
		|| addch('0') == ERR
		|| move(centre_x -2, centre_y) == ERR
		|| addch('0') == ERR
		|| move(centre_x -2, centre_y + 1) == ERR
		|| addch('0') == ERR


		|| move(centre_x -1, centre_y - 1) == ERR
		|| addch('0') == ERR
		|| move(centre_x -1, centre_y + 1) == ERR
		|| addch('0') == ERR

		|| move(centre_x , centre_y - 1) == ERR
		|| addch('0') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('0') == ERR
		
		|| move(centre_x + 1 , centre_y - 1) == ERR
		|| addch('0') == ERR
		|| move(centre_x + 1, centre_y + 1) == ERR
		|| addch('0') == ERR
		




		|| move(centre_x +2, centre_y - 1) == ERR
		|| addch('0') == ERR
		|| move(centre_x +2, centre_y) == ERR
		|| addch('0') == ERR
		|| move(centre_x +2, centre_y + 1) == ERR
		|| addch('0') == ERR)
		exit_ncurses(1);
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
	if (move(centre_x -2, centre_y - 1) == ERR
		|| addch('9') == ERR
		|| move(centre_x -2, centre_y) == ERR
		|| addch('9') == ERR
		|| move(centre_x -2, centre_y + 1) == ERR
		|| addch('9') == ERR
		|| move(centre_x -1, centre_y - 1) == ERR
		|| addch('9') == ERR
		|| move(centre_x -1, centre_y + 1) == ERR
		|| addch('9') == ERR
		|| move(centre_x , centre_y - 1) == ERR
		|| addch('9') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('9') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('9') == ERR
		|| move(centre_x + 1, centre_y + 1) == ERR
		|| addch('9') == ERR
		|| move(centre_x + 2, centre_y + 1) == ERR
		|| addch('9') == ERR)
		exit_ncurses(1);

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
	if (move(centre_x -2, centre_y - 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x -2, centre_y) == ERR
		|| addch('8') == ERR
		|| move(centre_x -2, centre_y + 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x -1, centre_y - 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x -1, centre_y + 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x, centre_y - 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('8') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x +1, centre_y - 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x +1, centre_y + 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x +2, centre_y - 1) == ERR
		|| addch('8') == ERR
		|| move(centre_x +2, centre_y) == ERR
		|| addch('8') == ERR
		|| move(centre_x +2, centre_y + 1) == ERR
		|| addch('8') == ERR)
		exit_ncurses(1);
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
	if (move(centre_x -2, centre_y - 1) == ERR
		|| addch('7') == ERR
		|| move(centre_x - 2, centre_y) == ERR
		|| addch('7') == ERR
		|| move(centre_x - 2, centre_y + 1) == ERR
		|| addch('7') == ERR
		|| move(centre_x -1, centre_y + 1) == ERR
		|| addch('7') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('7') == ERR
		|| move(centre_x + 1, centre_y + 1) == ERR
		|| addch('7') == ERR
		|| move(centre_x + 2, centre_y + 1) == ERR
		|| addch('7') == ERR)
		exit_ncurses(1);

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
	if (move(centre_x -2, centre_y - 1) == ERR
		|| addch('6') == ERR
		|| move(centre_x -1, centre_y - 1) == ERR
		|| addch('6') == ERR
		|| move(centre_x , centre_y - 1) == ERR
		|| addch('6') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('6') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('6') == ERR
		|| move(centre_x + 1, centre_y - 1) == ERR
		|| addch('6') == ERR
		|| move(centre_x + 1, centre_y + 1) == ERR
		|| addch('6') == ERR
		|| move(centre_x + 2, centre_y - 1) == ERR
		|| addch('6') == ERR
		|| move(centre_x + 2, centre_y) == ERR
		|| addch('6') == ERR
		|| move(centre_x + 2, centre_y + 1) == ERR
		|| addch('6') == ERR)
		exit_ncurses(1);
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
	if (move(centre_x - 2, centre_y - 1) == ERR
		|| addch('5') == ERR
		|| move(centre_x - 2, centre_y) == ERR
		|| addch('5') == ERR
		|| move(centre_x -2, centre_y + 1) == ERR
		|| addch('5') == ERR
		|| move(centre_x -1, centre_y - 1) == ERR
		|| addch('5') == ERR
		|| move(centre_x , centre_y - 1) == ERR
		|| addch('5') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('5') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('5') == ERR
		|| move(centre_x + 1, centre_y +1) == ERR
		|| addch('5') == ERR
		|| move(centre_x + 2, centre_y - 1) == ERR
		|| addch('5') == ERR
		|| move(centre_x + 2, centre_y) == ERR
		|| addch('5') == ERR
		|| move(centre_x +2, centre_y + 1) == ERR
		|| addch('5') == ERR)
		exit_ncurses(1);
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
	if (move(centre_x -2, centre_y - 1) == ERR
		|| addch('4') == ERR
		|| move(centre_x -2, centre_y + 1) == ERR
		|| addch('4') == ERR
		|| move(centre_x -1, centre_y - 1) == ERR
		|| addch('4') == ERR
		|| move(centre_x -1, centre_y + 1) == ERR
		|| addch('4') == ERR
		|| move(centre_x , centre_y - 1) == ERR
		|| addch('4') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('4') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('4') == ERR
		|| move(centre_x + 1, centre_y + 1) == ERR
		|| addch('4') == ERR
		|| move(centre_x + 2, centre_y + 1) == ERR
		|| addch('4') == ERR)
		exit_ncurses(1);
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
	if (move(centre_x - 2, centre_y - 1) == ERR
		|| addch('3') == ERR
		|| move(centre_x - 2, centre_y) == ERR
		|| addch('3') == ERR
		|| move(centre_x - 2, centre_y + 1) == ERR
		|| addch('3') == ERR
		|| move(centre_x -1, centre_y + 1) == ERR
		|| addch('3') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('3') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('3') == ERR
		|| move(centre_x + 1, centre_y + 1) == ERR
		|| addch('3') == ERR
		|| move(centre_x + 2, centre_y - 1) == ERR
		|| addch('3') == ERR
		|| move(centre_x + 2, centre_y) == ERR
		|| addch('3') == ERR
		|| move(centre_x + 2, centre_y + 1) == ERR
		|| addch('3') == ERR)
		exit_ncurses(1);
	
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
	if (move(centre_x -2 , centre_y - 1) == ERR
		|| addch('2') == ERR
		|| move(centre_x -2, centre_y) == ERR
		|| addch('2') == ERR
		|| move(centre_x -2, centre_y + 1) == ERR
		|| addch('2') == ERR
		|| move(centre_x -1, centre_y + 1) == ERR
		|| addch('2') == ERR
		|| move(centre_x , centre_y - 1) == ERR
		|| addch('2') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('2') == ERR
		|| move(centre_x , centre_y + 1) == ERR
		|| addch('2') == ERR
		|| move(centre_x + 1, centre_y - 1) == ERR
		|| addch('2') == ERR
		|| move(centre_x +2 , centre_y - 1) == ERR
		|| addch('2') == ERR
		|| move(centre_x +2, centre_y) == ERR
		|| addch('2') == ERR
		|| move(centre_x +2, centre_y + 1) == ERR
		|| addch('2') == ERR)
		exit_ncurses(1);
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
	if (move(centre_x -2, centre_y) == ERR
		|| addch('1') == ERR
		|| move(centre_x -1, centre_y) == ERR
		|| addch('1') == ERR
		|| move(centre_x , centre_y) == ERR
		|| addch('1') == ERR
		|| move(centre_x +1, centre_y) == ERR
		|| addch('1') == ERR
		|| move(centre_x +2, centre_y) == ERR
		|| addch('1') == ERR)
		exit_ncurses(1);

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
	else if (nbr == '0')
		return (print_zero(centre_x, centre_y));

}


void	print_ascii_num(int size, int map[5][5])
{
	int len_halfcase_y;
	int len_halfcase_x;

	len_halfcase_y = (COLS -1) / size / 2;

	len_halfcase_x = (LINES-1) / size / 2;

	int i = 0;
	int j = 0;
	int len_nbr;
	int n = 0;
	char *nbr;
	int	ncurs_ret;

	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (map[i][j] == 0)
				j++;
			else
			{
				ncurs_ret = 0;
				if (map[i][j] < 16)
					ncurs_ret = attron(COLOR_PAIR(1));
				else if (map[i][j] < 128)
					ncurs_ret = attron(COLOR_PAIR(2));
				else if (map[i][j] < 256)
					ncurs_ret = attron(COLOR_PAIR(3));
				else if (map[i][j] < 512)
					ncurs_ret = attron(COLOR_PAIR(4));
				else
					ncurs_ret = attron(COLOR_PAIR(5));
				if (ncurs_ret == ERR)
					exit_ncurses(1);
				nbr = ft_itoa(map[i][j]);
				if (!nbr)
					exit_ncurses(2);
				len_nbr = ft_strlen(nbr);
				n = 0;
				while (n < len_nbr)
				{
					print_nbr(nbr[n], len_halfcase_x + (LINES-1) * i / size, (len_halfcase_y + (COLS -1) * j / size) + ((-len_nbr /2 + n) * 5));
					n++;
				}
				free(nbr);
				ncurs_ret = 0;
				if (map[i][j] < 16)
					ncurs_ret = attroff(COLOR_PAIR(1));
				else if (map[i][j] < 128)
					ncurs_ret = attroff(COLOR_PAIR(2));

				else if (map[i][j] < 256)
					ncurs_ret = attroff(COLOR_PAIR(3));
				else if (map[i][j] < 512)
					ncurs_ret = attroff(COLOR_PAIR(4));
				else
					ncurs_ret = attroff(COLOR_PAIR(5));
				if (ncurs_ret == ERR)
					exit_ncurses(1);
				if (refresh() == ERR)
					exit_ncurses(1);
				j++;
			}
		}
		i++;
	}
}
