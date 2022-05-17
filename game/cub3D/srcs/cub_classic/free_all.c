/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 14:37:30 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:04:24 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/cub.h"

int	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (1);
}

void	free_setting(t_data *data)
{	
	int	i;

	i = 0;
	if (data->setting->wall != NULL)
	{
		while (i < 4)
		{
			if (data->setting->wall->text[i] != NULL)
				free(data->setting->wall->text[i]);
			if (data->setting->wall->img[i] != NULL)
				mlx_destroy_image(data->engine->mlx_ptr,
					data->setting->wall->img[i]);
			if (data->setting->wall->texturs[i] != NULL)
				free(data->setting->wall->texturs[i]);
			i++;
		}
		free(data->setting->wall);
	}
	free(data->setting);
}

void	free_engine(t_data *data)
{
	int	i;

	i = 0;
	if (data->engine->img.img)
		mlx_destroy_image(data->engine->mlx_ptr, data->engine->img.img);
	if (data->engine->map != NULL)
	{
		while (data->engine->map[i])
		{
			free(data->engine->map[i]);
			i++;
		}
		free(data->engine->map);
	}
	if (data->engine->win_ptr != NULL)
		mlx_destroy_window(data->engine->mlx_ptr, data->engine->win_ptr);
	if (data->engine->mlx_ptr != NULL)
	{
		mlx_destroy_display(data->engine->mlx_ptr);
		free(data->engine->mlx_ptr);
	}
	free(data->engine);
}

void	free_all(t_data *data)
{
	if (data->setting != NULL)
		free_setting(data);
	if (data->engine != NULL)
		free_engine(data);
}
