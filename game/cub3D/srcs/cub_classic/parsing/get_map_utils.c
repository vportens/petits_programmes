/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/25 17:53:12 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:04:48 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

int	is_wall_charactere(char c)
{
	int	i;

	i = 0;
	while (i < g_nbr_wall_charactere)
	{
		if (c == g_list_wall_charactere[i])
			return (1);
		i++;
	}
	return (0);
}

char	*free_all_getmap(char *s1, char *s2, int fd, char *line)
{
	free(s1);
	free(s2);
	free(line);
	close(fd);
	return (NULL);
}

void	*free_s2_line_ret_null(char *s2, char *line)
{
	free(s2);
	free(line);
	return (NULL);
}

void	init_inf(char **line, int *ret, char **s1, char **s2)
{
	*line = NULL;
	*ret = 2;
	*s1 = NULL;
	*s2 = NULL;
}
