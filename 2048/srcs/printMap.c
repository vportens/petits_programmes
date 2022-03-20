#include <ncurses.h>
#include <stdlib.h>
#include "game.h"



void	print_line(int size)
{
	int i;
	int j = 0;
	int point;

	while (j < size)
	{
		i = 0;
		point = (LINES - 1) * j / size;
		while (i < COLS)
		{
			if (move(point, i) == ERR
				|| addch('.') == ERR)
				exit_ncurses(1);
			i++;
		}
		j++;
	}

}

void	print_colonm(int size)
{
	int i = 0;
	int j;
	int point;

	while (i < size)
	{
		j = 0;
		point = (COLS - 1) * i/size;	
		while (j < LINES)
		{
			if (move(j, point) == ERR
				|| addch('.') == ERR)
				exit_ncurses(1);
			j++;
		}
		i++;
	}

}

void	print_border()
{
	int i = 0;
	int j = 0;
	
	while (i < COLS)
	{
		j = 0;
		while (j < LINES)
		{
			if (i == 0 || j == 0 || i == COLS - 1  || j == LINES - 1)
			{
				if (move(j, i) == ERR)
					exit_ncurses(1);
				addch('.');
			}
			j++;	
		}
		i++;
	}
}

void	print_score(int score)
{
	if (move(1, 1) == ERR
		|| printw("your score is : %i", score) == ERR)
		exit_ncurses(1);

}

void	print_map(int size) {

	if (clear() == ERR)
		exit_ncurses(1);
	print_border();
	print_colonm(size);
	print_line(size);
}


/*
int main() {

	int size = 5;

	initscr();				//Init la struc window et autre params

//	move(LINES -1, COLS-1);		//move to the endofline, endofcolomun
//	addch('.');		//right at the new pos

	print_map(size);
//	printw("hello world");				//Ecrit string a l'endroit la ou le curseur logique est
//	refresh()				//Rafraichit la fenetre courante afin de voir le message apparaitre
	getch();				//On attend que l'utilisateur appui sur un touche pour quitter	
	endwin();				//restaure les parametre par defaut du terminal
	return (0);

}
*/
