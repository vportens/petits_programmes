/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 14:09:51 by viporten          #+#    #+#             */
/*   Updated: 2021/12/26 15:11:45 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONFIG_H
# define CONFIG_H

# define POV 1.0

typedef enum e_to_pars
{
	P_TEXTURS_WALL_NSEW,
	P_TEXTURS_F_RGB,
	P_TEXTURS_C_RGB,
	P_MAP
}			t_to_pars;

static const char	g_list_valid_charactere[7] = {' ', '0', '1', 'N',
	'S', 'E', 'W'};
static const int	g_nbr_valid_charactere = 7;

static const char	g_list_wall_charactere[1] = {'1'};
static const int	g_nbr_wall_charactere = 1;

static const int	g_lst_to_pars[4] = {P_TEXTURS_WALL_NSEW,
	P_TEXTURS_F_RGB, P_TEXTURS_C_RGB, P_MAP};
static const int	g_len_lst_to_pars = 4;

int	get_textur_nsew(void *stc);
int	get_rgb_texturs(void *stc);

#endif
