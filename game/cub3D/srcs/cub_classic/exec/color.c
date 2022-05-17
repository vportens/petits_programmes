/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 05:54:31 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:05:19 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	get_color_wall(t_data *data, int y, int i, float height_wall)
{
	int	n;
	int	w;

	n = ((int)((data->setting->wall->height[i]) * (y / height_wall)));
	w = (int)(data->setting->text_precision * data->setting->wall->width[i]);
	if (n > 0)
		n--;
	if (w > 0)
		w--;
	return ((int)data->setting->wall->text[i]
		[(int)(data->setting->wall->width[i]
			* n)
		+ w]);
}

int	wich_wall(t_data *data, float alpha)
{
	if (data->setting->face == 0)
	{
		if (alpha > 0 && alpha < M_PI)
			return (0);
		return (1);
	}
	if (data->setting->face == 1)
	{
		if (alpha > M_PI / 2 && alpha < 3 * M_PI / 2)
			return (2);
		return (3);
	}
	return (-1);
}

void	color_wall(t_data *data, int x, float height_wall, float alpha)
{
	int		y;
	float	to;
	int		color;
	int		i;
	int		wall;

	y = (data->engine->screen_size_y - height_wall) / 2;
	i = 0;
	if (y < 0)
	{
		i = y * -1;
		y = 0;
	}
	to = height_wall + (data->engine->screen_size_y - height_wall) / 2;
	wall = wich_wall(data, alpha);
	while (y < to && y < data->engine->screen_size_y && i < height_wall)
	{
		color = get_color_wall(data, i, wall, height_wall);
		my_mlx_pixel_put(data, x, y, color);
		i++;
		y++;
	}
}

void	color_sky(t_data *data, int x, float height_wall)
{
	int		y;
	float	to;

	y = 0;
	if (height_wall >= (float)data->engine->screen_size_y)
		return ;
	to = (data->engine->screen_size_y - height_wall) / 2;
	while (y < to)
	{
		my_mlx_pixel_put(data, x, y, get_color(data->setting->rgb_ceilling[0],
				data->setting->rgb_ceilling[1],
				data->setting->rgb_ceilling[2]));
		y++;
	}
}

void	color_floor(t_data *data, int x, float height_wall)
{
	int		y;
	float	to;

	y = (data->engine->screen_size_y - height_wall) / 2 + height_wall;
	if (height_wall >= (float)data->engine->screen_size_y)
		return ;
	to = data->engine->screen_size_y;
	while (y < to)
	{
		my_mlx_pixel_put(data, x, y, get_color(data->setting->rgb_floor[0],
				data->setting->rgb_floor[1], data->setting->rgb_floor[2]));
		y++;
	}
}
