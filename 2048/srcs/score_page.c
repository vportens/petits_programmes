#include <ncurses.h>
#include "game.h"

int	score_page(char *file_name)
{
	int fd;
	char *line;
	int	i = 2;
	int j = 2;

	clear();
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0); 

	attron(A_BOLD | A_UNDERLINE);
	move(LINES/3, COLS/3);
	printw("High score 4 x 4");
	move(LINES/3, 2*COLS/3);
	printw("High score 5 x 5");
	attroff(A_BOLD | A_UNDERLINE);

	while (get_next_line(fd, &line))
	{
		if (line[0] == '4')
		{
			if (i == 2){
				attron(A_BOLD);
			}
			move(LINES / 3 + i, COLS / 3);
			printw(line + 1);
			if (i == 2){
				attroff(A_BOLD);
			}
			i++;
		}
		else if (line[0] == '5')
		{
			if (j == 2){
				attron(A_BOLD);
			}
			move(LINES / 3 + j, 2 * COLS / 3);
			printw(line + 1);
			if (j == 2){
				attroff(A_BOLD);
			}
			j++;
		}
		free(line);

	}
	refresh();
	getch();
	return (1);
}