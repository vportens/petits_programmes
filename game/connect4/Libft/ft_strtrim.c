/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 14:02:59 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/25 10:07:56 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isamong(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trim;
	unsigned int	start;
	unsigned int	end;

	start = 0;
	end = 0;
	trim = NULL;
	if (! s1 || !set)
		return (NULL);
	while (s1[start] && ft_isamong(s1[start], set))
		start++;
	if (ft_strlen(s1) <= 1)
		return (ft_substr(s1, 0, 0));
	while (end < ft_strlen(s1) && s1[ft_strlen(s1) - 1 - end]
		&& ft_isamong(s1[ft_strlen(s1) - 1 - end], set))
		end++;
	trim = ft_substr(s1, start, ft_strlen(s1) - start - end);
	if (! trim)
		return (NULL);
	return (trim);
}
