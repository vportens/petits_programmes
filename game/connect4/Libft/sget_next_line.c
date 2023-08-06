/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sget_next_line.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 10:11:39 by fle-blay          #+#    #+#             */
/*   Updated: 2022/06/12 14:21:01 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

char	*find_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (str + i);
		i++;
	}
	return (NULL);
}

int	load_input(int fd, char **line, char *buf, int buffer_size)
{
	int		read_ret;
	int		line_size;
	char	*appended_line;
	int		i;

	read_ret = read(fd, buf, buffer_size);
	if (read_ret <= 0)
		return (read_ret);
	line_size = ft_strlen(*line);
	appended_line = malloc((line_size + read_ret + 1) * sizeof(char));
	if (!appended_line)
		return (-2);
	appended_line[line_size + read_ret] = '\0';
	i = -1;
	while (++i < line_size)
		appended_line[i] = (*line)[i];
	while (read_ret--)
		appended_line[i + read_ret] = buf[read_ret];
	free(*line);
	*line = appended_line;
	return (1);
}

void	tailor_and_assign(char **line, char *buf, int buf_size, char **nxt_line)
{
	int		i;
	char	*start_new_buf;

	start_new_buf = find_nl(*line) + 1;
	i = 0;
	while (i < buf_size && start_new_buf[i])
	{
		buf[i] = start_new_buf[i];
		i++;
	}
	while (i < buf_size)
	{
		buf[i] = '\0';
		i++;
	}
	find_nl(*line)[1] = '\0';
	*nxt_line = *line;
}

int	sget_next_line(char **next_line, int fd)
{
	static char	buf[BUFFER_SIZE] = {};
	char		*line;
	int			load_ret;
	int			cumul_read;

	line = ft_strndup(buf, BUFFER_SIZE);
	if (!line)
		return (-2);
	load_ret = 1;
	cumul_read = 0;
	while (load_ret > 0 && !find_nl(line + cumul_read))
	{
		load_ret = load_input(fd, &line, buf, BUFFER_SIZE);
		cumul_read += load_ret;
	}
	if (load_ret < 0 || (!find_nl(line) && ft_strlen(line) == 0))
		return (free(line), load_ret);
	if (!find_nl(line))
	{
		ft_bzero(buf, BUFFER_SIZE);
		*next_line = line;
		return (1);
	}
	return (tailor_and_assign(&line, buf, BUFFER_SIZE, next_line), 1);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char *av[])
{
	char	*ret;
	int		ret_value;
	int		fd;

	if (ac != 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	ret_value = sget_next_line(&ret, fd);
	while (ret_value > 0)
	{
		printf("%s", ret);
		free(ret);
		ret_value = sget_next_line(&ret, fd);
	}
	return (0);
}
*/
