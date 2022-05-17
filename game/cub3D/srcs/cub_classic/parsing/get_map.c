/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/07 16:54:51 by victor            #+#    #+#             */
/*   Updated: 2022/01/01 20:04:46 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub.h"

static int	check_valide_charactere_in_line(char *str)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = 0;
		while (j < g_nbr_valid_charactere)
		{
			if (str[i] == g_list_valid_charactere[j])
				break ;
			j++;
		}
		if (j == g_nbr_valid_charactere)
			return (1);
		i++;
	}
	return (0);
}

void	replace_space_and_player_in_map(char **tab)
{
	int	i;
	int	j;

	i = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (tab[i][j] == ' ' || tab[i][j] == 'N'
				|| tab[i][j] == 'S' || tab[i][j] == 'W'
				|| tab[i][j] == 'E')
				tab[i][j] = '0';
			j++;
		}
		i++;
	}
}

int	check_valide_map(t_data *to_fill, char **tab)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tab && tab[i])
	{
		j = 0;
		while (tab[i][j])
		{
			if (!(is_wall_charactere(tab[i][j])) && tab[i][j] != ' ')
				if (check_aroud(to_fill, tab, i, j) != 0)
					return (1);
			j++;
		}
		i++;
	}
	replace_space_and_player_in_map(tab);
	return (0);
}

char	*extract_map(int fd)
{
	char	*line;
	int		ret;
	char	*s1;
	char	*s2;

	init_inf(&line, &ret, &s1, &s2);
	while (ret != 0)
	{
		ret = get_next_line(fd, &line);
		if (ret == -1 || check_valide_charactere_in_line(line) != 0)
			return (free_all_getmap(s1, s2, fd, line));
		if (s1 != NULL)
		{
			s2 = ft_strjoin(s1, ";");
			if (s2 == NULL)
				return (free_all_getmap(s1, s2, fd, line));
			free(s1);
		}
		s1 = ft_strjoin(s2, line);
		if (s1 == NULL)
			return (free_all_getmap(s1, s2, fd, line));
		s2 = free_s2_line_ret_null(s2, line);
	}
	return (s1);
}

int	get_map(int fd, t_data *to_fill)
{
	char	*flat_map;
	char	**tab;

	flat_map = extract_map(fd);
	if (flat_map == NULL)
		return (1);
	close(fd);
	tab = ft_strsplit(flat_map, ';');
	free(flat_map);
	if (tab == NULL)
		return (1);
	if (check_valide_map(to_fill, tab) != 0)
		return (free_tab(tab));
	to_fill->engine->map = tab;
	if (to_fill->setting->pos[0] == -1)
		return (1);
	return (0);
}
