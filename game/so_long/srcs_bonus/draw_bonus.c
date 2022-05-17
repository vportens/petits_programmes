/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:22:43 by laclide           #+#    #+#             */
/*   Updated: 2021/09/08 18:57:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	draw_ennemie(t_long *stc, int j, int i)
{
	int	res;

	res = stc->timer / 36;
	if ((res == 1)
		&& stc->map[stc->ss_y + i / 64][stc->ss_x - 1 + j / 64] != '1')
	{
		j = j - 64;
	}
	else if (res == 3
		&& stc->map[stc->ss_y + i / 64][stc->ss_x + 1 + j / 64] != '1')
	{
		j = j + 64;
	}
	mlx_put_image_to_window(stc->mlx, stc->win, stc->ennemie.img, (j), (i));
	if (stc->pos_y == stc->ss_y + i / 64 && stc->pos_x == stc->ss_x + j / 64)
		stc->game_over = 1;
	return (0);
}

int	draw_obj_to_window(t_long *stc, int i, int j)
{
	if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == '1')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->wall.img, (j),
			(i));
	if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == '0')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->sand.img, (j),
			(i));
	if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == 'E')
		mlx_put_image_to_window(stc->mlx, stc->win, stc->i_exit.img,
			(j), (i));
	return (0);
}

int	draw_obj(t_long *stc, int i, int j)
{
	while (i < stc->screen_height)
	{
		j = 0;
		while (j < stc->screen_width)
		{
			if (stc->ss_x + j / 64 >= 0 && (stc->ss_y
					+ i / 64) >= 0
				&& (stc->ss_x + j / 64) < stc->len_map_x && (stc->ss_y + i / 64)
				< stc->len_map_y)
				draw_obj_to_window(stc, i, j);
			j = j + 64;
		}
		i = i + 64;
	}
	return (0);
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
	mlx_string_put(stc->mlx, stc->win, 64, 64, color(255, 255, 255), tmp);
	free(str);
	free(tmp);
	draw_player(stc);
	return (0);
}

int	draw_bonus(t_long *stc, int i, int j)
{
	stc->timer++;
	if (stc->timer % 144 == 0)
		stc->timer = 0;
	stc->ss_x = stc->pos_x - stc->screen_width / 128;
	stc->ss_y = stc->pos_y - stc->screen_height / 128;
	if (stc->game_over == 1)
		return (1);
	draw_background(stc);
	draw_obj(stc, 0, 0);
	draw_coin(stc, 0, 0);
	while (i < stc->screen_height)
	{
		j = 0;
		while (j < stc->screen_width)
		{
			if ((stc->ss_x + j / 64) >= 0 && (stc->ss_y + i / 64) >= 0
				&& (stc->ss_x + j / 64) < stc->len_map_x && (stc->ss_y
					+ i / 64) < stc->len_map_y && stc->map[stc->ss_y + i
					/ 64][stc->ss_x + j / 64] == 'B')
				draw_ennemie(stc, j, i);
			j = j + 64;
		}
		i = i + 64;
	}
	return (draw_end(stc));
}
