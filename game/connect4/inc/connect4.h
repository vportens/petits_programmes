#ifndef CONNECT4_H
# define CONNECT4_H

# define ERROR -1
# define INPUT_EOF 0

# define SIZEMAX 400
# define LINE_MIN 6
# define COLUMN_MIN 7
# define AI 1
# define PLAYER 2

# define SILENT 0
# define VERBOSE 1

# ifndef DEBUG
#  define DEBUG 0
# endif

typedef struct s_game
{
	int	**board;
	int	lines;
	int	columns;
	int	game_over;
	int	player_answer;
	int	ai_answer;
	int	move_read;
	int	begin;
} t_game;

int		init_game(t_game *game, int ac, char *av[]);
int		allocate_board(t_game *game);
int		get_param(t_game *game, char *arg1, char *arg2);
void	partial_destroy_board(t_game *game, int stop);
void	display_board(t_game *game);
void	display_winner(t_game *game);
void	clear_screen(void);
void	display_numbers(t_game *game);
int		get_move(t_game *game);
void	make_move(t_game *game, int move, int who);
void	remove_move(t_game *game, int move);
int		ai_random_move(t_game *game);
int		ai_pseudo_smart_move(t_game *game);
int		check_player_input(t_game *game, char *input);
int		check_ai_input(t_game *game, int input);
int		check_position_row(t_game *game, int i, int j, int who, int verbose);
int		check_position_column(t_game *game, int i, int j, int who, int verbose);
int		check_position_rdiag(t_game *game, int i, int j, int who, int verbose);
int		check_position_ldiag(t_game *game, int i, int j, int who, int verbose);
int		position_align_score(t_game *game, int i, int j, int who, int verbose);
int		check_winner(t_game *game, int verbose);
int		get_max_align(t_game *game, int who);
int		board_full(t_game *game);
int		get_align_score(t_game *game, int who);

# endif
