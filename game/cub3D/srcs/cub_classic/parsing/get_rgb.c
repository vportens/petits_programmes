/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_rgb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 21:44:03 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:04:43 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	close_and_free(int fd, char *str)
{
	free(str);
	close(fd);
	return (1);
}

static int	len_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
		i++;
	return (i);
}

int	fill_rgb(int *to_fill, char *with, char identifier)
{
	int		i;
	char	**tab;

	i = 0;
	if (with[0] && with[0] != identifier)
		return (1);
	i++;
	while (with[i] && with[i] == ' ')
		i++;
	tab = ft_strsplit(with + i, ',');
	if (len_tab(tab) != 3)
		return (free_tab(tab));
	if (!(ft_true_atoi(&(to_fill[0]), tab[0]))
		|| !(ft_true_atoi(&(to_fill[1]), tab[1]))
		|| !(ft_true_atoi(&(to_fill[2]), tab[2])))
		return (free_tab(tab));
	if ((to_fill[0]) > 255 || (to_fill[0]) < 0
		|| (to_fill[1]) > 255 || (to_fill[1]) < 0
		|| (to_fill[2]) > 255 || (to_fill[2]) < 0)
		return (free_tab(tab));
	free_tab(tab);
	return (0);
}

int	get_rgb(int fd, int *to_fill, char identifier)
{
	int		ret;
	char	*line;

	line = NULL;
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1)
			return (close_and_free(fd, line));
		if (line != NULL && line[0] != '\0')
		{
			if (fill_rgb(to_fill, line, identifier) != 0)
				return (close_and_free(fd, line));
			else
				break ;
		}
		free(line);
	}
	free(line);
	return (0);
}
