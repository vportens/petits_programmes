/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:35:34 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:05:00 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	get_tab_img(t_data *data, int i)
{
	int	x;
	int	y;

	while (i < 4)
	{
		x = 0;
		data->setting->wall->text[i] = malloc(sizeof(int)
				* (data->setting->wall->width[i]
					* data->setting->wall->height[i]));
		if (data->setting->wall->text[i] == NULL)
			return (1);
		while (x < data->setting->wall->width[i])
		{
			y = -1;
			while (++y < data->setting->wall->height[i])
				data->setting->wall->text[i][data->setting->wall->width[i]
					* y + x] = ((int *)data->setting->wall->addr[i])
				[data->setting->wall->width[i] * y + x];
			x++;
		}
		i++;
	}
	return (0);
}

int	convert_xpm_ptr(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		data->setting->wall->img[i] = mlx_xpm_file_to_image(
				data->engine->mlx_ptr, data->setting->wall->texturs[i],
				&(data->setting->wall->width[i]),
				&(data->setting->wall->height[i]));
		if (data->setting->wall->img[i] == NULL)
			return (1);
		data->setting->wall->addr[i] = mlx_get_data_addr(
				data->setting->wall->img[i], &(data->setting->wall->bpp[i]),
				&(data->setting->wall->sp[i]),
				&(data->setting->wall->endian[i]));
		if (data->setting->wall->addr[i] == NULL)
			return (1);
		i++;
	}
	if (get_tab_img(data, 0) == 1)
		return (1);
	return (0);
}

int	start(t_data *data)
{
	data->engine->mlx_ptr = mlx_init();
	if (data->engine->mlx_ptr == NULL)
		return (1);
	if (convert_xpm_ptr(data) != 0)
		return (1);
	mlx_get_screen_size(data->engine->mlx_ptr, &data->engine->screen_size_x,
		&data->engine->screen_size_y);
	data->engine->win_ptr = mlx_new_window(data->engine->mlx_ptr,
			data->engine->screen_size_x, data->engine->screen_size_y,
			"Cub3D by viporten and rmechety");
	draw(data);
	mlx_hook(data->engine->win_ptr, 2, (1L << 0), mouve, (void *)data);
	mlx_hook(data->engine->win_ptr, 17, 0L, exit_game, (void *)data);
	mlx_loop_hook(data->engine->mlx_ptr, draw, (void *)data);
	mlx_loop(data->engine->mlx_ptr);
	return (0);
}
