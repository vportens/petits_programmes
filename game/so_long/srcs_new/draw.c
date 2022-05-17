/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:22:43 by laclide           #+#    #+#             */
/*   Updated: 2021/08/12 11:57:58 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	pos_start_screen(t_long *stc)
{
	stc->ss_x = stc->pos_x - stc->screen_width / 128;
	stc->ss_y = stc->pos_y - stc->screen_height / 128;
	return (0);
}

int	draw_ennemie(t_long *stc, int j, int i)
{
	int	res;

	res = stc->timer / 16;
	if ((res == 0 || res == 2)
		&& stc->map[stc->ss_y + i / 64][stc->ss_x - 1 + j / 64] != '1')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->ennemie.img,
			(j - 64), (i));
		if (stc->pos_y == stc->ss_y + i / 64 && stc->pos_x == stc->ss_x
			- 1 + j / 64)
			stc->game_over = 1;
	}
	if (res == 1 || res == 3)
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->ennemie.img,
			(j), (i));
		if (stc->pos_y == stc->ss_y + i / 64 && stc->pos_x == stc->ss_x
			+ j / 64)
			stc->game_over = 1;
	}
	return (0);
}

int	draw_obj(t_long *stc, int i, int j)
{
	if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == '1')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->wall.img, (j), (i));
	if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == '0')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->sand.img, (j), (i));
	if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == 'C')
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->target.img,
			(j), (i));
	}
	if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == 'E')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->i_exit.img, (j), (i));
	return (draw_player(stc));
}

int	draw_end(t_long *stc)
{
	char	*str;
	char	*tmp;

	str = NULL;
	if (stc->game_over == 1)
	{
		draw_background(stc);
		mlx_string_put(stc->mlx, stc->win, stc->screen_width / 2,
			stc->screen_height / 2, color(255, 255, 255), "game_over");
		return (1);
	}
	str = ft_itoa(stc->nbr_move);
	tmp = ft_strjoin("your score is : ", str);
	free(str);
	free(tmp);
	return (0);
}

int	draw(t_long *stc, int i, int j)
{
	i = 0;
	if (stc->game_over == 1)
		return (1);
	draw_background(stc);
	pos_start_screen(stc);
	stc->addr = mlx_get_data_addr(stc->img, &stc->bpp, &stc->l_l, &stc->endian);
	while (i < stc->screen_height)
	{
		j = 0;
		while (j < stc->screen_width)
		{
			if ((stc->ss_x + j / 64) >= 0 && (stc->ss_y + i / 64) >= 0
				&& (stc->ss_x + j / 64) < stc->len_map_x && (stc->ss_y + i / 64)
				< stc->len_map_y)
				draw_obj(stc, i, j);
			j = j + 64;
		}
		i = i + 64;
	}
	return (draw_end(stc));
}
