/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_img.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:04:47 by laclide           #+#    #+#             */
/*   Updated: 2021/08/23 15:11:47 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_sprite(t_long *stc)
{
	int		i;
	char	*c;
	char	*tmp;

	i = 0;
	while (i < 24)
	{
		c = ft_itoa(i + 1);
		tmp = ft_strjoin("./texture_xpm/coin", c);
		stc->target[i].path = ft_strjoin(tmp, ".xpm");
		free(c);
		free(tmp);
		stc->target[i].img = mlx_xpm_file_to_image(stc->mlx,
				stc->target[i].path,
				&stc->target[i].witdh, &stc->target[i].height);
		i++;
	}
}

void	init_path(t_long *stc)
{
	stc->target = malloc(sizeof(t_imgs) * 24);
	stc->player_right.path = "./texture_xpm/player_right.xpm";
	stc->player_left.path = "./texture_xpm/player_left.xpm";
	stc->i_exit.path = "./texture_xpm/exit.xpm";
	stc->ennemie.path = "./texture_xpm/ennemie.xpm";
	stc->wall.path = "./texture_xpm/wall.xpm";
	stc->sand.path = "./texture_xpm/sand.xpm";
	init_sprite(stc);
}

int	init_img(t_long *stc)
{
	init_path(stc);
	stc->player_left.img = mlx_xpm_file_to_image(stc->mlx,
			stc->player_left.path,
			&stc->player_left.witdh, &stc->player_left.height);
	stc->player_right.img = mlx_xpm_file_to_image(stc->mlx,
			stc->player_right.path,
			&stc->player_right.witdh, &stc->player_right.height);
	stc->sand.img = mlx_xpm_file_to_image(stc->mlx, stc->sand.path,
			&stc->sand.witdh, &stc->sand.height);
	stc->i_exit.img = mlx_xpm_file_to_image(stc->mlx, stc->i_exit.path,
			&stc->i_exit.witdh, &stc->i_exit.height);
	stc->ennemie.img = mlx_xpm_file_to_image(stc->mlx, stc->ennemie.path,
			&stc->ennemie.witdh, &stc->ennemie.height);
	stc->wall.img = mlx_xpm_file_to_image(stc->mlx, stc->wall.path,
			&stc->wall.witdh, &stc->wall.height);
	stc->player = stc->player_right;
	return (0);
}
