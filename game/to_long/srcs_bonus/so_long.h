/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:38:30 by laclide           #+#    #+#             */
/*   Updated: 2021/09/08 18:36:28 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libft/includes/libft.h"
# include "../minilibx-linux/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_imgs
{
	void	*img;
	int		witdh;
	int		height;
	char	*path;
}				t_imgs;

typedef struct s_long
{
	char	*file_line;
	char	**map;
	int		len_map_x;
	int		len_map_y;
	int		pos_x;
	int		pos_y;
	int		nbr_collectible;
	int		exit_x;
	int		exit_y;
	int		nbr_move;
	char	*print;
	void	*mlx;
	void	*win;
	void	*img;
	char	*addr;
	int		endian;
	int		bpp;
	int		l_l;
	int		screen_width;
	int		screen_height;
	t_imgs	sand;
	t_imgs	*target;
	t_imgs	player;
	t_imgs	player_right;
	t_imgs	player_left;
	t_imgs	i_exit;
	t_imgs	ennemie;
	t_imgs	wall;
	int		ss_x;
	int		ss_y;
	int		timer;
	int		frame;
	int		game_over;
}				t_long;

int		parsing_name(int ac, char **av);
int		parsing(char *file, t_long *stc);
int		parsing_bonus(char *file, t_long *stc);
int		read_and_file(char *file, t_long *stc);
int		error(int i);
int		rec_gnl(int fd, char **line);
int		check_fill_inf_line(char *line, t_long *stc);
int		check_fill_inf_line_bonus(char *line, t_long *stc);
int		check_inf(t_long *stc, int i, int j);
int		creat_map(t_long *stc);
int		init_size_screen(t_long *stc);
void	my_mlx_pixel_put(t_long *stc, int x, int y, int color);
int		color(int r, int g, int b);
int		clean(t_long *stc);
int		draw_background(t_long *stc);
int		draw(t_long *stc, int i, int j);
int		draw_bonus(t_long *stc, int i, int j);
int		keycode(int key, t_long *stc);
int		init_img(t_long *stc);
void	init_stc(t_long *stc);
int		mlx_exit(t_long *stc);
int		draw_player(t_long *stc);
void	remove_score(t_long *stc);
void	print_score(t_long *stc);
void	print_final_score(t_long *stc);
int		init_img(t_long *stc);
int		draw_coin(t_long *stc, int i, int j);

#endif
