/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_raycast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 06:46:06 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:04:57 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

float	get_angle_x(float x, float alpha)
{
	if (alpha == M_PI / 2 || alpha == 3 * M_PI / 2)
		x = 0;
	else if (alpha <= 0 && alpha < M_PI / 2)
		x = x / cos(alpha);
	else if (alpha > M_PI / 2 && alpha <= M_PI)
		x = x / cos(M_PI - alpha);
	else if (alpha > M_PI && alpha < 3 * M_PI / 2)
		x = x / cos(alpha - M_PI);
	else if (alpha > 3 * M_PI / 2 && alpha < 2 * M_PI)
		x = x / cos (2 * M_PI - alpha);
	x = fabs(x);
	return (x);
}

float	get_first_x(t_data *data, float alpha)
{
	float	x;

	if (alpha > M_PI / 2 && alpha < 3 * M_PI / 2)
		x = fabs(data->setting->pos[1] - floor(data->setting->pos[1]));
	else
		x = fabs(ceil(data->setting->pos[1]) - data->setting->pos[1]);
	if (alpha == M_PI / 2 || alpha == 3 * M_PI / 2)
	{
		x = 0;
	}
	x = get_angle_x(x, alpha);
	return (x);
}

float	get_angle_y(float y, float alpha)
{
	if (alpha == M_PI || alpha == 2 * M_PI)
		y = 0;
	else if (alpha > 0 && alpha <= M_PI / 2)
		y = y / cos(M_PI / 2 - alpha);
	else if (alpha > M_PI && alpha <= 3 * M_PI / 2)
		y = y / (cos(M_PI / 2 - alpha - M_PI));
	else if (alpha > M_PI / 2 && alpha < M_PI)
		y = y / cos(alpha - M_PI / 2);
	else if (alpha > 3 * M_PI / 2 && alpha < 2 * M_PI)
		y = y / cos(alpha - 3 * M_PI / 2);
	y = fabs(y);
	return (y);
}

float	get_first_y(t_data *data, float alpha)
{
	float	y;

	if (alpha < M_PI && alpha > 0)
		y = fabs(floor(data->setting->pos[0]) - data->setting->pos[0]);
	else
		y = fabs(ceil(data->setting->pos[0]) - data->setting->pos[0]);
	return (get_angle_y(y, alpha));
}
