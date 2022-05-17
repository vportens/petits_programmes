/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texturs_nsew.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/06 17:12:23 by viporten          #+#    #+#             */
/*   Updated: 2022/01/01 20:04:38 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	free_line_close_fd_ret_int(char *line, int fd)
{
	free(line);
	close(fd);
	return (1);
}

static int	check_first_character(char *with, int *i)
{
	if (*i == 0 && (with[0] != 'N' || with[1] != 'O'))
		return (1);
	else if (*i == 1 && (with[0] != 'S' || with[1] != 'O'))
		return (1);
	else if (*i == 2 && (with[0] != 'W' || with[1] != 'E'))
		return (1);
	else if (*i == 3 && (with[0] != 'E' || with[1] != 'A'))
		return (1);
	return (0);
}

static int	fill_textur(t_textur_nsew_wall *to_fill, char *with, int *i)
{
	int	len;
	int	j;

	if (with[0] == '\0')
		return (0);
	len = ft_strlen(with);
	if (len < 2)
		return (1);
	if (check_first_character(with, i) != 0)
		return (1);
	j = 2;
	while (with[j] == ' ')
		j++;
	to_fill->texturs[*i] = ft_strdup(with + j);
	if (to_fill->texturs[*i] == NULL || to_fill->texturs[*i][0] == '\0')
		return (1);
	*i = *i + 1;
	return (0);
}

static void	init_textur_nsew(t_textur_nsew_wall *to_init)
{
	to_init->texturs[0] = NULL;
	to_init->texturs[1] = NULL;
	to_init->texturs[2] = NULL;
	to_init->texturs[3] = NULL;
	to_init->img[0] = NULL;
	to_init->img[1] = NULL;
	to_init->img[2] = NULL;
	to_init->img[3] = NULL;
	to_init->addr[0] = NULL;
	to_init->addr[1] = NULL;
	to_init->addr[2] = NULL;
	to_init->addr[3] = NULL;
	to_init->text[0] = NULL;
	to_init->text[1] = NULL;
	to_init->text[2] = NULL;
	to_init->text[3] = NULL;
}

int	get_texturs_nsew(int fd, t_data *to_fill)
{
	int					ret;
	char				*line;
	int					i;

	line = NULL;
	i = 0;
	to_fill->setting->wall = malloc(sizeof(t_textur_nsew_wall));
	init_textur_nsew((t_textur_nsew_wall *)to_fill->setting->wall);
	while (1)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1 || ret == 0)
			return (free_line_close_fd_ret_int(line, fd));
		if (fill_textur(to_fill->setting->wall, line, &i) != 0)
			return (free_line_close_fd_ret_int(line, fd));
		if (i == 4)
			break ;
		free(line);
	}
	free(line);
	return (0);
}
