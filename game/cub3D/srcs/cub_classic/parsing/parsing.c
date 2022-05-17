/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 03:16:59 by victor            #+#    #+#             */
/*   Updated: 2022/01/01 20:05:28 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_name_extention(char *name, char *extention)
{
	int	len;
	int	len_extention;

	len = ft_strlen(name);
	len_extention = ft_strlen(extention);
	if (len <= len_extention)
		return (1);
	if (!(ft_strcmp(name + (len - len_extention), extention)))
		return (1);
	return (0);
}

int	parsing(char *av, t_data *to_fill)
{
	int	i;

	i = 0;
	if (init_t_data(to_fill) == 1 || check_name_extention(av, ".cub") != 0)
		return (4);
	to_fill->fd = open(av, O_RDONLY);
	if (to_fill->fd == -1)
		return (1);
	while (i < g_len_lst_to_pars)
	{
		if (g_lst_to_pars[i] == P_TEXTURS_WALL_NSEW)
			if (get_texturs_nsew(to_fill->fd, to_fill) != 0)
				return (5);
		if (g_lst_to_pars[i] == P_TEXTURS_F_RGB)
			if (get_rgb(to_fill->fd, to_fill->setting->rgb_floor, 'F') != 0)
				return (6);
		if (g_lst_to_pars[i] == P_TEXTURS_C_RGB)
			if (get_rgb(to_fill->fd, to_fill->setting->rgb_ceilling, 'C') != 0)
				return (7);
		if (g_lst_to_pars[i] == P_MAP)
			if (get_map(to_fill->fd, to_fill) != 0)
				return (8);
		i++;
	}
	return (0);
}
