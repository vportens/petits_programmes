/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 10:38:13 by laclide           #+#    #+#             */
/*   Updated: 2021/09/08 17:52:42 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	move_up_down(int key, t_long *stc)
{
	if (key == 119)
	{
		if (stc->map[stc->pos_y - 1][stc->pos_x] != '1')
		{
			stc->pos_y--;
			stc->nbr_move++;
			remove_score(stc);
			print_score(stc);
		}
	}
	if (key == 115)
	{
		if (stc->map[stc->pos_y + 1][stc->pos_x] != '1')
		{
			stc->pos_y++;
			stc->nbr_move++;
			remove_score(stc);
			print_score(stc);
		}
	}
	return (0);
}

int	move_left_right(int key, t_long *stc)
{
	if (key == 97)
	{
		if (stc->map[stc->pos_y][stc->pos_x - 1] != '1')
		{
			stc->nbr_move++;
			stc->pos_x--;
			stc->player = stc->player_left;
			remove_score(stc);
			print_score(stc);
		}
	}
	if (key == 100)
	{
		if (stc->map[stc->pos_y][stc->pos_x + 1] != '1')
		{
			stc->pos_x++;
			stc->nbr_move++;
			stc->player = stc->player_right;
			remove_score(stc);
			print_score(stc);
		}
	}
	return (0);
}

int	keycode(int key, t_long *stc)
{
	if (key == 97 || key == 100)
		move_left_right(key, stc);
	if (key == 119 || key == 115)
		move_up_down(key, stc);
	if (stc->map[stc->pos_y][stc->pos_x] == 'C')
	{
		stc->nbr_collectible--;
		stc->map[stc->pos_y][stc->pos_x] = '0';
	}
	if ((stc->map[stc->pos_y][stc->pos_x] == 'E'
		&& stc->nbr_collectible == 0) || (key == 65307 && stc->timer != -1))
	{
		return (mlx_exit(stc));
	}
	draw(stc, 0, 0);
	stc->timer++;
	return (0);
}
