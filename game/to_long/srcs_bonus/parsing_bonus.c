/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laclide <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/28 11:14:26 by laclide           #+#    #+#             */
/*   Updated: 2021/07/29 16:58:38 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	parsing_name(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac != 2)
		return (1);
	while (av[1][i])
		i++;
	if (i < 4)
		return (2);
	i--;
	if (av[1][i] != 'r' || av[1][i - 1] != 'e' || av[1][i - 2] != 'b'
		|| av[1][i - 3] != '.')
		return (2);
	return (0);
}

int	end_read(char *line, int fd, int i)
{
	if (line)
		free(line);
	if (close(fd) != 0)
		return (error(30));
	if (i != 0)
	{
		write(1, "Error\nvide\n", 11);
		return (1);
	}
	return (0);
}

int	read_and_file_bonus(char *file, t_long *stc)
{
	int		fd;
	char	*line;
	int		res;
	int		i;

	line = NULL;
	i = -1;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (error(40));
	res = rec_gnl(fd, &line);
	while (res > 0)
	{
		i = check_fill_inf_line_bonus(line, stc);
		if (line)
			free(line);
		line = NULL;
		if (i != 0)
			break ;
		res = rec_gnl(fd, &line);
	}
	return (end_read(line, fd, i));
}

int	parsing_bonus(char *file, t_long *stc)
{
	if (read_and_file_bonus(file, stc) != 0)
		return (4);
	if (creat_map(stc) != 0)
		return (4);
	return (0);
}
