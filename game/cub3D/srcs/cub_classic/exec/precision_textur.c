/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_textur.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:24:07 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:05:05 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

void	cut_precision(t_data *data, float alpha)
{
	data->setting->text_precision = data->setting->text_precision
		- floor(data->setting->text_precision);
	if (data->setting->face == 1)
	{
		if (alpha > M_PI / 2 && alpha < 3 * M_PI / 2)
			data->setting->text_precision = 1 - data->setting->text_precision;
	}
	if (data->setting->face == 0)
	{
		if (alpha > M_PI && alpha < 2 * M_PI)
			data->setting->text_precision = 1 - data->setting->text_precision;
	}
}

void	get_text_precision(t_data *data, float len, float alpha)
{
	float	new;

	new = get_new_alpha(alpha);
	if (data->setting->face == 0)
	{
		if ((alpha >= 0 && alpha < M_PI / 2) || (alpha > 3 * M_PI
				/ 2 && alpha <= 2 * M_PI))
			data->setting->text_precision = data->setting->pos[1]
				+ (len * sin(new));
		if (alpha > M_PI / 2 && alpha < 3 * M_PI / 2)
			data->setting->text_precision = data->setting->pos[1]
				- (len * sin(new));
	}
	else if (data->setting->face == 1)
	{
		if (alpha > 0 && alpha < M_PI)
			data->setting->text_precision = data->setting->pos[0]
				- (len * cos(new));
		if (alpha > M_PI && alpha < 2 * M_PI)
			data->setting->text_precision = data->setting->pos[0]
				+ (len * cos(new));
	}
	cut_precision(data, alpha);
}
