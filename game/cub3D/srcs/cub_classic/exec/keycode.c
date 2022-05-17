/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/24 13:51:59 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:05:08 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

float	asdw(int keycode)
{
	if (keycode == 119)
		return (0);
	if (keycode == 115)
		return (-M_PI);
	if (keycode == 100)
		return (-M_PI / 2);
	if (keycode == 97)
		return (M_PI / 2);
	return (-1);
}

int	exit_game(void *new)
{
	t_data	*data;

	data = (t_data *)new;
	free_all(data);
	exit(0);
}

int	mouve(int keycode, void *inf)
{
	t_data	*data;
	float	new_x;
	float	new_y;
	float	angle;

	data = (t_data *)inf;
	if (keycode == 65307)
		exit_game(data);
	if (keycode == 65361)
		data->setting->dir += 0.1;
	if (keycode == 65363)
		data->setting->dir -= 0.1;
	angle = asdw(keycode);
	if (angle != -1)
	{
		new_x = data->setting->pos[1] + 0.1 * cos(data->setting->dir + angle);
		new_y = data->setting->pos[0] - 0.1 * sin(data->setting->dir + angle);
		if (data->engine->map[(int)(new_y)][(int)(new_x)] != '1')
		{
			data->setting->pos[1] = new_x;
			data->setting->pos[0] = new_y;
		}
	}
	return (0);
}
