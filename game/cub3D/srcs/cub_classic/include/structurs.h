/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structurs.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 13:39:07 by viporten          #+#    #+#             */
/*   Updated: 2021/12/25 18:05:05 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURS_H
# define STRUCTURS_H

# include "../libft/includes/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>

typedef enum e_type
{
	NON,
	TEXTURE_NSEW_WALL,
	TEXTURE_WALL,
	TEXTURE_SPRIT
}			t_type;

typedef struct s_textur_nsew_wall
{
	char	*texturs[4];
	void	*img[4];
	char	*addr[4];
	int		bpp[4];
	int		sp[4];
	int		endian[4];
	int		width[4];
	int		height[4];
	int		*text[4];

}				t_textur_nsew_wall;

typedef struct s_setting
{
	int					res[2];
	float				pos[2];
	float				dir;
	int					rgb_floor[3];
	int					rgb_ceilling[3];
	t_textur_nsew_wall	*wall;
	float				text_precision;
	float				new_alpha;
	float				step_cos_alpha;
	float				step_sin_alpha;
	float				pos_x;
	float				pos_y;
	float				h_x;
	float				h_y;
	int					face;
}				t_setting;

typedef struct s_img
{
	void	*img;
	void	*img_addr;
	int		bpp;
	int		ll;
	int		endian;
}				t_img;

typedef struct s_engine
{
	char	**map;
	void	*mlx_ptr;
	int		screen_size_y;
	int		screen_size_x;
	void	*win_ptr;
	t_img	img;
}				t_engine;

typedef struct s_data
{
	int			fd;
	t_setting	*setting;
	t_engine	*engine;
}				t_data;

#endif
