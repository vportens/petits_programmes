/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 16:54:32 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:04:22 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub.h"

void	init_t_setting(t_data *to_init)
{
	to_init->setting->res[0] = -1;
	to_init->setting->res[1] = -1;
	to_init->setting->pos[0] = -1;
	to_init->setting->pos[1] = -1;
	to_init->setting->dir = -10;
	to_init->setting->rgb_floor[0] = -1;
	to_init->setting->rgb_floor[1] = -1;
	to_init->setting->rgb_floor[2] = -1;
	to_init->setting->rgb_ceilling[0] = -1;
	to_init->setting->rgb_ceilling[1] = -1;
	to_init->setting->rgb_ceilling[2] = -1;
	to_init->setting->wall = NULL;
}

void	init_t_engine(t_data *to_init)
{
	to_init->engine->map = NULL;
	to_init->engine->mlx_ptr = NULL;
	to_init->engine->win_ptr = NULL;
	to_init->engine->img.img = NULL;
	to_init->engine->img.img_addr = NULL;
}

int	init_t_data(t_data *to_init)
{
	to_init->setting = malloc(sizeof(t_setting));
	if (to_init->setting == NULL)
		return (1);
	init_t_setting(to_init);
	to_init->engine = malloc(sizeof(t_engine));
	if (to_init->engine == NULL)
		return (1);
	init_t_engine(to_init);
	return (0);
}
