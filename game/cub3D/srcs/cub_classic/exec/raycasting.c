/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 00:01:17 by viporten          #+#    #+#             */
/*   Updated: 2022/01/22 16:15:21 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	draw_line(t_data *data, float len_player_to_wall, int x, float alpha)
{
	float	height_wall;

	height_wall = data->engine->screen_size_y / len_player_to_wall;
	color_sky(data, x, height_wall);
	color_wall(data, x, height_wall, alpha);
	color_floor(data, x, height_wall);
}

void	init_val(float alpha, t_data *data, float *d_x, float *d_y)
{
	data->setting->pos_y = data->setting->pos[0];
	data->setting->pos_x = data->setting->pos[1];
	data->setting->step_cos_alpha = 1 / cos(data->setting->new_alpha);
	data->setting->step_sin_alpha = 1 / sin(data->setting->new_alpha);
	get_delta(alpha, data, d_x, d_y);
	data->setting->h_y = *d_y * data->setting->step_cos_alpha;
	data->setting->h_x = *d_x * data->setting->step_sin_alpha;
}

int	is_wall(t_data *data)
{
	if (data->engine->map[(int)data->setting->pos_y]
		[(int)data->setting->pos_x] == '1')
		return (1);
	return (0);
}

float	send_a_ray(t_data *data, float alpha)
{
	float	delta_x;
	float	delta_y;

	init_val(alpha, data, &delta_x, &delta_y);
	while (1)
	{
		if (data->setting->h_x < data->setting->h_y || alpha == 0)
		{
			data->setting->face = 1;
			data->setting->pos_x = define_pos_x(alpha, data->setting->pos_x);
			if (is_wall(data))
				return (data->setting->h_x);
			data->setting->h_x += data->setting->step_sin_alpha;
		}
		else
		{
			data->setting->face = 0;
			data->setting->pos_y = define_pos_y(alpha, data->setting->pos_y);
			if (is_wall(data))
				return (data->setting->h_y);
			data->setting->h_y += data->setting->step_cos_alpha;
		}
	}
	return (0);
}

int	ray_casting(t_data *data)
{
	int		i;
	float	len_player_to_wall;
	float	angle_ray;

	i = 0;
	angle_ray = data->setting->dir + POV / 2;
	while (i < data->engine->screen_size_x)
	{
		while (angle_ray < 0)
			angle_ray = 2 * M_PI + angle_ray;
		while (angle_ray > 2 * M_PI)
			angle_ray = angle_ray - 2 * M_PI;
		data->setting->new_alpha = get_new_alpha(angle_ray);
		len_player_to_wall = send_a_ray(data, angle_ray);
		get_text_precision(data, len_player_to_wall, angle_ray);
		len_player_to_wall = len_player_to_wall
			* (cos(fabs(angle_ray - data->setting->dir)));
		draw_line(data, len_player_to_wall, i, angle_ray);
		angle_ray -= POV / data->engine->screen_size_x;
		i++;
	}
	return (0);
}
