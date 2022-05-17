/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_ennemie_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:22:43 by laclide           #+#    #+#             */
/*   Updated: 2021/07/28 12:20:37 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_bomb_left(t_long *stc, int j, int i)
{
	mlx_put_image_to_window(stc->mlx, stc->win, stc->ennemie.img,
		(j - 64), (i));
	if (stc->pos_y == stc->ss_y + i / 64 && stc->pos_x == stc->ss_x - 1
		+ j / 64)
		stc->game_over = 1;
}

int	draw_ennemie(t_long *stc, int j, int i)
{
	int	res;

	res = stc->timer / 16;
	if ((res == 0 || res == 2)
		&& stc->map[stc->ss_y + i / 64][stc->ss_x - 1 + j / 64] != '1')
		draw_bomb_left(stc, j, i);
	else if (res == 0 || res == 2)
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->ennemie.img, (j), (i));
		if (stc->pos_y == stc->ss_y + i / 64 && stc->pos_x == stc->ss_x
			+ j / 64)
			stc->game_over = 1;
	}
	if (res == 1 || res == 3)
	{
		mlx_put_image_to_window(stc->mlx, stc->win, stc->ennemie.img, (j), (i));
		if (stc->pos_y == stc->ss_y + i / 64 && stc->pos_x == stc->ss_x
			+ j / 64)
			stc->game_over = 1;
	}
	return (0);
}
