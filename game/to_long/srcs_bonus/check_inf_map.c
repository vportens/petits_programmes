/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inf_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 23:28:01 by laclide           #+#    #+#             */
/*   Updated: 2021/07/31 19:09:38 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_exit(t_long *stc, int i, int j)
{
	if (stc->map[i][j] == 'E')
	{
		stc->exit_x = j;
		stc->exit_y = i;
	}
	return (0);
}

int	check_pos_player(t_long *stc, int i, int j)
{
	if (stc->map[i][j] == 'P')
	{
		stc->pos_x = j;
		stc->pos_y = i;
	}
	return (0);
}

int	check_last_wall(t_long *stc, int i, int j)
{
	if (stc->map[i][j] != '1')
		return (8);
	return (0);
}

int	check_first_line_or_first_wall(t_long *stc, int i, int j)
{
	if ((i == 0 || j == 0) && stc->map[i][j] != '1')
		return (1);
	return (0);
}

int	check_inf(t_long *stc, int i, int j)
{
	if ((i == 0 || j == 0) && check_first_line_or_first_wall(stc, i, j) != 0)
		return (error(7));
	if (check_pos_player(stc, i, j) != 0)
		return (error(10));
	if (check_exit(stc, i, j) != 0)
		return (error(11));
	if (stc->map[i][j] == 'C')
		stc->nbr_collectible++;
	if (stc->map[i][j + 1] == '\0' || stc->map[i + 1] == NULL)
	{
		if (check_last_wall(stc, i, j) != 0)
			return (error(7));
	}
	return (0);
}
