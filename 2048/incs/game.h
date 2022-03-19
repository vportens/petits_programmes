#ifndef	GAME_H 
#define	GAME_H 

enum e_const
{
	WIN_VALUE = 32
};

char	*ft_itoa(int nbr);
void	print_map(int size);
void	print_ascii_num(int size, int map[5][5]);
void	print_game(int map[5][5], int size);
int		merge_left(int board[5][5], int size);
int		merge_right(int board[5][5], int size);
int		merge_up(int board[5][5], int size);
int		merge_down(int board[5][5], int size);
int		move_left(int board[5][5], int size);
int		move_right(int board[5][5], int size);
int		move_up(int board[5][5], int size);
int		move_down(int board[5][5], int size);
int		is_full(int board[5][5], int size);
int		add_number(int board[5][5], int size);
int		is_game_over(int board[5][5], int size);
int		play_round(int board[5][5], int size);
int		play_game(int size);

#endif
