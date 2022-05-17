/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_val_raycast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:25:27 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:05:10 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

float	get_new_alpha(float alpha)
{
	if (alpha >= 0 && alpha <= M_PI / 2)
		return (M_PI / 2 - alpha);
	if (alpha > M_PI / 2 && alpha <= M_PI)
		return (alpha - M_PI / 2);
	if (alpha > M_PI && alpha < 3 * M_PI / 2)
		return (3 * M_PI / 2 - alpha);
	if (alpha >= 3 * M_PI / 2 && alpha < 2 * M_PI)
		return (alpha - 3 * M_PI / 2);
	return (0);
}

int	define_pos_x(float alpha, int pos_x)
{
	if (alpha < M_PI / 2 || alpha > 3 * M_PI / 2)
		pos_x++;
	else if (alpha > M_PI / 2 && alpha < 3 * M_PI / 2)
		pos_x--;
	return (pos_x);
}

int	define_pos_y(float alpha, int pos_y)
{
	if (alpha > 0 && alpha < M_PI)
		pos_y--;
	else if (alpha > M_PI && alpha < 2 * M_PI)
		pos_y++;
	return (pos_y);
}

void	get_delta(float alpha, t_data *data, float *x, float *y)
{
	*y = 0;
	*x = 0;
	if (alpha > 0 && alpha < M_PI)
		*y = data->setting->pos[0] - floor(data->setting->pos[0]);
	else if (alpha > M_PI && alpha < 2 * M_PI)
	{
		*y = ceil(data->setting->pos[0]) - data->setting->pos[0];
		if (*y == 0)
			*y = 1;
	}
	if (alpha > M_PI / 2 && alpha < 3 * M_PI / 2)
		*x = data->setting->pos[1] - floor(data->setting->pos[1]);
	else if (alpha < M_PI / 2 || alpha > 3 * M_PI / 2)
		*x = ceil(data->setting->pos[1]) - data->setting->pos[1];
	return ;
}
