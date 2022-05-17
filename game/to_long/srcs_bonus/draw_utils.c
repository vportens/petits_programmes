/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 23:02:40 by laclide           #+#    #+#             */
/*   Updated: 2021/09/08 18:57:41 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	my_mlx_pixel_put(t_long *stc, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x <= stc->screen_width && y >= 0 && y < stc->screen_height)
	{
		dst = stc->addr + (y * stc->l_l + x * (stc->bpp / 8));
		*(unsigned int *)dst = color;
	}
}

int	color(int r, int g, int b)
{
	if (r > 255 || b > 255 || g > 255 || r < 0 || b < 0 || g < 0)
		return (-1);
	else
		return (r << 16 | g << 8 | b);
}

int	draw_background(t_long *stc)
{
	int	i;
	int	j;

	i = 0;
	while (i < stc->screen_height)
	{
		j = 0;
		while (j < stc->screen_width)
		{
			mlx_put_image_to_window(stc->mlx, stc->win, stc->sand.img, j, i);
			j = j + 64;
		}
		i = i + 64;
	}
	return (0);
}

int	draw_player(t_long *stc)
{
	mlx_put_image_to_window(stc->mlx, stc->win, stc->player.img,
		stc->screen_width / 2, stc->screen_height / 2);
	return (0);
}

int	draw_coin(t_long *stc, int i, int j)
{
	stc->timer++;
	if (stc->timer % 144 == 0)
		stc->timer = 0;
	i = 0;
	while (i < stc->screen_height)
	{
		j = 0;
		while (j < stc->screen_width)
		{
			if (stc->ss_x + j / 64 >= 0 && (stc->ss_y + i / 64) >= 0
				&& (stc->ss_x + j / 64) < stc->len_map_x
				&& (stc->ss_y + i / 64) < stc->len_map_y)
			{
				if (stc->map[stc->ss_y + i / 64][stc->ss_x + j / 64] == 'C'
					&& stc->timer < 144)
					mlx_put_image_to_window(stc->mlx, stc->win,
						stc->target[stc->timer / 6].img, (j), (i));
			}
			j = j + 64;
		}
		i = i + 64;
	}
	return (0);
}
