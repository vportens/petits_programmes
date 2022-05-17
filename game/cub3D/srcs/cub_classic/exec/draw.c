/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 21:59:59 by viporten          #+#    #+#             */
/*   Updated: 2022/01/22 16:11:37 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

unsigned int	get_color(int r, int g, int b)
{
	return (b + (g << 8) + (r << 16));
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->engine->img.img_addr + (y * data->engine->img.ll + x
			* (data->engine->img.bpp / 8));
	*(unsigned int *)dst = color;
}

int	draw(t_data *data)
{
	if (data->engine->img.img == NULL)
	{
		data->engine->img.img = mlx_new_image(data->engine->mlx_ptr,
				data->engine->screen_size_x, data->engine->screen_size_y);
		data->engine->img.img_addr = mlx_get_data_addr(data->engine->img.img,
				&data->engine->img.bpp, &data->engine->img.ll,
				&data->engine->img.endian);
	}
	ray_casting(data);
	mlx_put_image_to_window(data->engine->mlx_ptr, data->engine->win_ptr,
		data->engine->img.img, 0, 0);
	return (0);
}
