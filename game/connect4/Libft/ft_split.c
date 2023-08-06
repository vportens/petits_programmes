/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:35:10 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/26 15:15:09 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countwd(char const *s, char c)
{
	int		count;
	size_t	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static size_t	ft_lenskp(char const *s, int *start, char c, int skip)
{
	int		i;
	size_t	len;

	i = 0;
	len = 0;
	while (skip && s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			skip--;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	while (s[i] && s[i] == c)
		i++;
	*start = i;
	while (s[i + len] && s[i + len] != c)
		len++;
	return (len);
}

static void	*ft_destroytab(char **tab, int index)
{
	int	i;

	i = 0;
	if (tab)
	{
		while (i < index)
		{
			if (tab[i])
			{
				free(tab[i]);
				tab[i] = NULL;
			}
			i++;
		}
		free(tab);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		start;
	int		countwd;
	int		lenwd;
	int		i;

	start = 0;
	lenwd = 0;
	i = 0;
	if (! s)
		return (NULL);
	countwd = ft_countwd(s, c);
	tab = (char **)malloc((countwd + 1) * sizeof(char *));
	if (! tab)
		return (NULL);
	while (i < countwd)
	{
		lenwd = ft_lenskp(s, &start, c, i);
		tab[i] = ft_substr(s, start, lenwd);
		if (! tab[i])
			return (ft_destroytab(tab, i));
		i++;
	}
	tab[i] = NULL;
	return (tab);
}
