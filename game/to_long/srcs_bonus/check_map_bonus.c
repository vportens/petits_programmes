/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:11:27 by laclide           #+#    #+#             */
/*   Updated: 2021/07/28 11:39:03 by laclide          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	valid_map(t_long *stc, int i, int j)
{
	if (stc->map == NULL)
		return (error(5));
	while (stc->map[i])
	{
		j = 0;
		while (stc->map[i][j])
		{
			if (check_inf(stc, i, j) != 0)
				return (1);
			j++;
		}
		if (stc->len_map_x != -1)
			if (j != stc->len_map_x)
				return (error(6));
		stc->len_map_x = j;
		i++;
	}
	stc->len_map_y = i;
	if (stc->pos_x == -1 || stc->exit_x == -1)
		return (error(11));
	if (stc->nbr_collectible == 0)
		return (error(13));
	return (0);
}

int	creat_map(t_long *stc)
{
	stc->map = ft_strsplit(stc->file_line, '.');
	if (stc->map == NULL)
		return (error(50));
	if (valid_map(stc, 0, 0) != 0)
		return (1);
	return (0);
}

int	list_valid_caracter_bonus(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != 'E'
			&& line[i] != 'P' && line[i] != 'C' && line[i] != 'B')
			return (1);
		i++;
	}
	return (0);
}

int	check_fill_inf_line_bonus(char *line, t_long *stc)
{
	char	*tmp;

	tmp = NULL;
	if (list_valid_caracter_bonus(line) != 0)
		return (error(4));
	if (stc->file_line != NULL)
		tmp = ft_strjoin(stc->file_line, ".");
	if (stc->file_line)
		free(stc->file_line);
	stc->file_line = tmp;
	tmp = ft_strjoin(stc->file_line, line);
	if (stc->file_line)
		free(stc->file_line);
	stc->file_line = tmp;
	if (stc->file_line == NULL)
		return (error(50));
	return (0);
}
