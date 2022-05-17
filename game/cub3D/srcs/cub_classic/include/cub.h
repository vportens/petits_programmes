/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:03:24 by viporten          #+#    #+#             */
/*   Updated: 2022/01/22 18:43:53 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H

# include "structurs.h"
# include "parsing.h"
# include "config.h"
# include "math.h"
# include "mlx.h"

int				init_t_data(t_data *to_init);

int				get_texturs_nsew(int fd, t_data *to_fill);
int				get_rgb(int fd, int *to_fill, char identifier);

int				get_map(int fd, t_data *to_fill);
int				check_aroud(t_data *to_fill, char **tab, int y, int x);
int				is_wall_charactere(char c);
int				free_tab(char **tab);
char			*free_all_getmap(char *s1, char *s2, int fd, char *line);
void			*free_s2_line_ret_null(char *s2, char *line);
void			init_inf(char **line, int *ret, char **s1, char **s2);

int				start(t_data *data);
int				draw(t_data *data);
int				ray_casting(t_data *data);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
unsigned int	get_color(int r, int g, int b);

int				get_color_wall(t_data *data, int y, int i, float height_wall);

void			color_wall(t_data *data, int x, float height_wall, float alpha);
void			color_sky(t_data *data, int x, float height_wall);
void			color_floor(t_data *data, int x, float height_wall);

float			get_first_y(t_data *data, float alpha);
float			get_angle_y(float y, float alpha);
float			get_first_x(t_data *data, float alpha);
float			get_angle_x(float x, float alpha);
float			get_new_alpha(float alpha);
int				define_pos_x(float alpha, int pos_x);
int				define_pos_y(float alpha, int pos_y);
void			get_delta(float alpha, t_data *data, float *x, float *y);
void			get_text_precision(t_data *data, float len, float alpha);
void			cut_precision(t_data *data, float alpha);

void			free_all(t_data *data);

int				mouve(int keycode, void *inf);
int				exit_game(void *new);

#endif
