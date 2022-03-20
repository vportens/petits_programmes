#include <ncurses.h>
#include "game.h"


char *create_new_score(int size, int score)
{
	char *c_size;
	char *c_score;
	char *fusion;

	c_size = ft_itoa(size);
	c_score = ft_itoa(score);
	fusion = ft_strjoin(c_size, c_score);
	free(c_score);	
	free(c_size);	
	
	return (fusion);
}



int	add_score_to_file(int size, int score, char *pseudo, char *file_name)
{
	char *new_score;
	new_score = create_new_score(size, score);
	char *add_speudo = ft_strjoin(new_score, " ");
	char *to_add;
	to_add = ft_strjoin(add_speudo, pseudo);

	free(add_speudo);
	free(new_score);

	int fd;
	char *line;

	int ret;
	int to_cmp = ft_atoi(to_add);

	char **tab;

	tab = malloc(sizeof(char *) * 12);
	if (tab == NULL)
		return (0);
	int i = 0;
	while (i < 12)
	{
		tab[i] = NULL;
		i++;
	}	

	int bob = 0;

	fd = open(file_name, O_RDONLY);	
	if (fd < 0)
		return (0);
	i = 0;
	while (get_next_line(fd, &line))
	{
		ret = ft_atoi(line);
		if (ret < to_cmp && i < 12 && bob == 0)
		{
			tab[i] = to_add;
			i++;
			bob = 1;
		}
		if (i < 12)
			tab[i] = line;
		else
			free(line);
		i++;
	}
	free(line);
	close(fd);

	int fd_new;
	fd_new = open("score.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	
	if (fd_new < 0)
		return (0);
	i = 0;
	while (tab[i])
	{
		write(fd_new, tab[i], ft_strlen(tab[i]));
		write(fd_new, "\n", 1);

		i++;
	}
	close(fd_new);
	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);

}

int is_high_score(int size, int score, char *pseudo, char *file_name)
{
	int fd;
	char *line;
	int i  = 0;	
	int score_file;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (0);

	while (get_next_line(fd, &line))
	{
		score_file = ft_atoi(line + 1);
		if (score > score_file)
		{
			close(fd);
			free(line);
			add_score_to_file(size, score, pseudo, file_name);
			return (1);
		}
		free(line);
		i++;
	}
	close(fd);
	return (1);
}

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
			if (i < 7)
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
		}
		else if (line[0] == '5')
		{
			if (j < 7)
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
		}
		free(line);

	}
	free(line);
	close(fd);
	refresh();
	getch();
	return (1);
}
