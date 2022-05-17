/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:04:47 by laclide           #+#    #+#             */
/*   Updated: 2021/08/17 19:35:53 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_path(t_long *stc)
{
	stc->player_right.path = "./texture_xpm/player_right.xpm";
	stc->player_left.path = "./texture_xpm/player_left.xpm";
	stc->target.path = "./texture_xpm/coin1.xpm";
	stc->i_exit.path = "./texture_xpm/exit.xpm";
	stc->ennemie.path = "./texture_xpm/ennemie.xpm";
	stc->wall.path = "./texture_xpm/wall.xpm";
	stc->sand.path = "./texture_xpm/sand.xpm";
}

int	init_img(t_long *stc)
{
	init_path(stc);
	stc->player_right.img = mlx_xpm_file_to_image(stc->mlx,
			stc->player_right.path,
			&stc->player_right.witdh, &stc->player_right.height);
	stc->player_left.img = mlx_xpm_file_to_image(stc->mlx,
			stc->player_left.path,
			&stc->player_left.witdh, &stc->player_left.height);
	stc->sand.img = mlx_xpm_file_to_image(stc->mlx, stc->sand.path,
			&stc->sand.witdh, &stc->sand.height);
	stc->target.img = mlx_xpm_file_to_image(stc->mlx, stc->target.path,
			&stc->target.witdh, &stc->target.height);
	stc->i_exit.img = mlx_xpm_file_to_image(stc->mlx, stc->i_exit.path,
			&stc->i_exit.witdh, &stc->i_exit.height);
	stc->ennemie.img = mlx_xpm_file_to_image(stc->mlx, stc->ennemie.path,
			&stc->ennemie.witdh, &stc->ennemie.height);
	stc->wall.img = mlx_xpm_file_to_image(stc->mlx, stc->wall.path,
			&stc->wall.witdh, &stc->wall.height);
	stc->player = stc->player_right;
	return (0);
}
