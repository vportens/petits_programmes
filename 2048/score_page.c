#include <ncurses.h>
#include "game.h"
#include <fcntl.h>

int	score_page(char *file_name)
{
	int fd;
	char *line;
	int	i = 0;
	int j = 0;

	clear();
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0); 

	while (get_next_line(fd, &line))
	{
		if (line[0] == '4')
		{
			move(LINES / 3 + i, COLS / 3);
			printw(line + 1);
			i++;
		}
		else if (line[0] == '5')
		{
			move(LINES / 3 + j, 2 * COLS / 3);
			printw(line + 1);
			j++;
		}
		free(line);

	}
	return (1);
}