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

void	free_tab(char **tab)
{
	int i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

int	creat_and_fill_file(char **tab, char *file_name)
{
	int fd_new;
	int i;

	i = 0;
	fd_new = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_new < 0)
	{
		free_tab(tab);
		return (0);
		}
	while (tab[i])
	{
		write(fd_new, tab[i], ft_strlen(tab[i]));
		write(fd_new, "\n", 1);
		i++;
	}
	close(fd_new);
	free_tab(tab);
	return (1);
		
}

char *line_to_add(int size, int score, char *pseudo)
{
	char *new_score;
	char *add_speudo;
	char *to_add;

	new_score = create_new_score(size, score);
	add_speudo = ft_strjoin(new_score, " ");
	to_add = ft_strjoin(add_speudo, pseudo);
	free(add_speudo);
	free(new_score);

	return (to_add);
}

int	creat_fill_score(char *line, char *file_name)
{
	int fd_new;

	fd_new = open(file_name, O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd_new < 0)
	{
		free(line);
		return (0);
	}
	write(fd_new, line, ft_strlen(line));
	free(line);
	close(fd_new);
	return (0);

}

int	add_score_to_file(int size, int score, char *pseudo, char *file_name)
{
	int fd;
	char *to_add = line_to_add(size, score, pseudo);
	char *line;

	int ret;
	int to_cmp = ft_atoi(to_add);

	char **tab;
	tab = malloc(sizeof(char *) * 11);
	if (tab == NULL)
		return (0);

	int i = 0;
	while (i < 11)
	{
		tab[i] = NULL;
		i++;
	}	


	fd = open(file_name, O_RDONLY);	
	if (fd < 0)
	{
		free(tab);
		creat_fill_score(to_add, file_name);
		return (0);
	}

	i = 0;
	int bob = 0;
	int ret_gnl;
	while ((ret_gnl = get_next_line(fd, &line)) > 0)
	{

		ret = ft_atoi(line);
		if (ret < to_cmp && i < 10 && bob == 0)
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
	if (ret_gnl < 0)
	{
		free(tab);
		close(fd);
		return (0);
	}
	ret = ft_atoi(line);
	if (ret < to_cmp && i < 10 && bob == 0)
	{
		tab[i] = to_add;
		i++;
		bob = 1;
	}
	if (i < 10)
		tab[i] = line;
	i++;
	close(fd);

	creat_and_fill_file(tab, file_name);
	if (bob == 0)
		free(to_add);
	return (1);
}



int is_high_score(int size, int score, char *pseudo, char *file_name)
{
	int fd;
	char *line;
	int i  = 0;	
	int score_file;
	int ret;

	int q;
	int c;

	q = 0;
	c = 0;
	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
		add_score_to_file(size, score, pseudo, file_name);
		return (1);
	}
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		if (line[0] == '4')
			q++;
		else if (line[0] == '5')
			c++;
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
	if (ret < 0)
	{
		close(fd);
		return (0);
	}
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
	if ((size == 4 && q < 5) || (size == 5 && c < 5))
	{
		close(fd);
		add_score_to_file(size, score, pseudo, file_name);
		return (1);
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

	attron(A_BOLD | A_UNDERLINE);
	move(LINES/3, COLS/3);
	printw("High score 4 x 4");
	move(LINES/3, 2*COLS/3);
	printw("High score 5 x 5");
	attroff(A_BOLD | A_UNDERLINE);

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
	{
	refresh();
	getch();
		return (0); 
	}
	int ret;
	while ((ret = get_next_line(fd, &line)) > 0)
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
	if (ret < 0)
	{
	refresh();
	getch();
		close(fd);
		return (1);
	}
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
	close(fd);
	refresh();
	getch();
	return (1);
}
