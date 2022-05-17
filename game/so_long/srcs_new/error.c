/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 11:06:26 by laclide           #+#    #+#             */
/*   Updated: 2021/08/17 19:37:44 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	destroy_imgs(t_long *stc)
{
	if (stc->player_left.img)
		mlx_destroy_image(stc->mlx, stc->player_left.img);
	if (stc->player_right.img)
		mlx_destroy_image(stc->mlx, stc->player_right.img);
	if (stc->target.img)
		mlx_destroy_image(stc->mlx, stc->target.img);
	if (stc->i_exit.img)
		mlx_destroy_image(stc->mlx, stc->i_exit.img);
	if (stc->ennemie.img)
		mlx_destroy_image(stc->mlx, stc->ennemie.img);
	if (stc->wall.img)
		mlx_destroy_image(stc->mlx, stc->wall.img);
	if (stc->sand.img)
		mlx_destroy_image(stc->mlx, stc->sand.img);
}

int	clean(t_long *stc)
{
	int	i;

	i = 0;
	if (stc->file_line)
		free(stc->file_line);
	if (stc->map)
	{
		while (stc->map[i])
		{
			free(stc->map[i]);
			i++;
		}
		free(stc->map);
	}
	destroy_imgs(stc);
	return (1);
}

void	error_sys(int i)
{
	if (i == 30)
		write(1, "close error\n", 12);
	else if (i == 40)
		write(1, "open error\n", 11);
	else if (i == 50)
		write(1, "malloc error\n", 13);
}

int	error(int i)
{
	write(1, "Error\n", 6);
	if (i == 1)
		write(1, "bad nbr arg\n", 12);
	else if (i == 2)
		write(1, "bad name file\n", 13);
	else if (i == 3)
		write(1, "invalid file\n", 13);
	else if (i == 4)
		write(1, "invalid caracatere\n", 19);
	else if (i == 6)
		write(1, "map pas carre\n", 14);
	else if (i == 7)
		write(1, "map pas ferme\n", 15);
	else if (i == 10)
		write(1, "no player\n", 10);
	else if (i == 11)
		write(1, "no exit\n", 8);
	else if (i == 12)
		write(1, "no exit or player\n", 18);
	else if (i == 13)
		write(1, "no coin\n", 8);
	error_sys(i);
	return (1);
}
