/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_around.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:26:06 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:04:51 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	check_pos(t_data *to_fill, char **tab, int y, int x)
{
	if (to_fill->setting->pos[0] != -1)
		return (1);
	to_fill->setting->pos[0] = y + 0.5;
	to_fill->setting->pos[1] = x + 0.5;
	if (tab[y][x] == 'N')
		to_fill->setting->dir = M_PI / 2;
	if (tab[y][x] == 'S')
		to_fill->setting->dir = -M_PI / 2;
	if (tab[y][x] == 'E')
		to_fill->setting->dir = 0;
	if (tab[y][x] == 'W')
		to_fill->setting->dir = M_PI;
	return (0);
}

int	check_line_up(char **tab, int y, int x)
{
	int	len_line_up;

	len_line_up = ft_strlen(tab[y - 1]);
	if (len_line_up < x + 2)
		return (0);
	if (tab[y - 1][x - 1] == ' ' || tab[y - 1][x] == ' '
		|| tab[y - 1][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_cur_line(char **tab, int y, int x)
{
	int	len;

	len = ft_strlen(tab[y]);
	if (len == x)
		return (0);
	if (tab[y][x - 1] == ' ' || tab[y][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_line_down(char **tab, int y, int x)
{
	int	len_down;

	if (!tab[y + 1])
		return (0);
	len_down = ft_strlen(tab[y + 1]);
	if (len_down < x + 2)
		return (0);
	if (tab[y + 1][x - 1] == ' ' || tab[y + 1][x] == ' '
		|| tab[y + 1][x + 1] == ' ')
		return (0);
	return (1);
}

int	check_aroud(t_data *to_fill, char **tab, int y, int x)
{
	if (y == 0 || x == 0)
		return (1);
	if (!check_line_up(tab, y, x))
		return (1);
	if (!check_cur_line(tab, y, x))
		return (1);
	if (!check_line_down(tab, y, x))
		return (1);
	if (tab[y][x] == 'N' || tab[y][x] == 'S'
		|| tab[y][x] == 'W' || tab[y][x] == 'E')
		return (check_pos(to_fill, tab, y, x));
	return (0);
}
