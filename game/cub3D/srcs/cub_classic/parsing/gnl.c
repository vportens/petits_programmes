/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/05 03:25:46 by victor            #+#    #+#             */
/*   Updated: 2022/01/01 20:04:35 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	line_init(char **line, int offset, int res)
{
	(*line = malloc((offset + 1) * sizeof(char)));
	if ((*line) == NULL)
		return (-1);
	((*line)[offset]) = '\0';
	return (res);
}

static int	recursive_gnl(char **line, int fd, int offset)
{
	char	buff;
	int		ret;

	ret = read(fd, &buff, 1);
	if (ret == 1)
	{
		if (buff == '\n' || buff == '\0')
			return (line_init(line, offset, 1));
		else
		{
			ret = recursive_gnl(line, fd, offset + 1);
			if ((*line) != NULL)
				((*line)[offset]) = buff;
			return (ret);
		}
	}
	else if (ret == 0)
		return (line_init(line, offset, 0));
	return (-1);
}

int	get_next_line(int fd, char **line)
{
	char	buff;

	if (fd < 0 || !line || read(fd, &buff, 0) < 0)
	{
		return (-1);
	}
	*line = NULL;
	return (recursive_gnl(line, fd, 0));
}
