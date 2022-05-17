/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:04:47 by laclide           #+#    #+#             */
/*   Updated: 2021/09/08 17:53:09 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_stc(t_long *stc)
{
	stc->file_line = NULL;
	stc->map = NULL;
	stc->pos_x = -1;
	stc->pos_y = -1;
	stc->nbr_collectible = 0;
	stc->exit_x = -1;
	stc->exit_y = -1;
	stc->nbr_move = 0;
	stc->len_map_x = -1;
	stc->len_map_y = -1;
	stc->timer = 0;
	stc->frame = 0;
	stc->screen_width = 1024;
	stc->screen_height = 640;
	stc->game_over = 0;
	stc->player.img = NULL;
	stc->player_right.img = NULL;
	stc->player_left.img = NULL;
	stc->target.img = NULL;
	stc->i_exit.img = NULL;
	stc->ennemie.img = NULL;
	stc->wall.img = NULL;
	stc->sand.img = NULL;
}

int	mlx_exit(t_long *stc)
{
	print_final_score(stc);
	clean(stc);
	stc->game_over = 1;
	mlx_destroy_image(stc->mlx, stc->img);
	mlx_destroy_window(stc->mlx, stc->win);
	mlx_destroy_display(stc->mlx);
	free(stc->mlx);
	exit(0);
	return (0);
}

int	image(t_long *stc)
{
	write(1, "your score is  0", 16);
	stc->mlx = mlx_init();
	stc->win = mlx_new_window(stc->mlx, stc->screen_width, stc->screen_height,
			"./so_long");
	stc->img = mlx_new_image(stc->mlx, stc->screen_width, stc->screen_height);
	if (init_img(stc) != 0)
		return (1);
	if (draw(stc, 0, 0) != 0)
		return (1);
	mlx_key_hook(stc->win, keycode, stc);
	mlx_hook(stc->win, 17, 0L, mlx_exit, stc);
	mlx_loop(stc->mlx);
	return (0);
}

int	main(int ac, char **av)
{
	t_long	stc;
	int		res;

	res = parsing_name(ac, av);
	if (res != 0)
		return (error(res));
	init_stc(&stc);
	res = parsing(av[1], &stc);
	if (res != 0)
	{
		clean(&stc);
		return (1);
	}
	if (image(&stc) != 0)
	{
		mlx_exit(&stc);
		return (0);
	}
	return (0);
}
