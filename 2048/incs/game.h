#ifndef	GAME_H 
#define	GAME_H 

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

enum e_const
{
	WIN_VALUE = 1
};


char	*ft_itoa(int nbr);
void	print_map(int size);
void	print_ascii_num(int size, int map[5][5]);
void	print_game(int map[5][5], int size, int score);
int		merge_left(int board[5][5], int size, int *score);
int		merge_right(int board[5][5], int size, int *score);
int		merge_up(int board[5][5], int size, int *score);
int		merge_down(int board[5][5], int size, int *score);
int		move_left(int board[5][5], int size, int *score);
int		move_right(int board[5][5], int size, int *score);
int		move_up(int board[5][5], int size, int *score);
int		move_down(int board[5][5], int size, int *score);
int		is_full(int board[5][5], int size);
int		add_number(int board[5][5], int size);
int		is_game_over(int board[5][5], int size);
int		play_round(int board[5][5], int size, int *score);
int		play_game(int size, char *name);
void	exit_ncurses(int code);
void	print_score(int score);
int		game_over_screen(int score, char *name);

int	get_next_line(int fd, char **line);
int	score_page(char *file_name);
int	ft_atoi(char *str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strdup(const char *s1);
char	*ft_strnew(size_t size);

void	*ft_memalloc(size_t size);
void	*ft_memset(void *b, int c, size_t len);
int ft_strlen(const char *nbr);
int is_high_score(int size, int score, char *pseudo, char *file_name);

#endif
