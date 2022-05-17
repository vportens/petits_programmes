/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_size_screen.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 22:44:38 by laclide           #+#    #+#             */
/*   Updated: 2021/07/28 12:18:14 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	init_size_screen(t_long *stc)
{
	if (stc->len_map_x * 64 > 1024)
		stc->screen_width = 1024;
	else
		stc->screen_width = stc->len_map_x * 64;
	if (stc->len_map_y * 64 > 640)
		stc->screen_height = 640;
	else
		stc->screen_height = stc->len_map_y * 64;
	return (0);
}
