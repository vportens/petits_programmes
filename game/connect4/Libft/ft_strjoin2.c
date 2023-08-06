/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 09:51:31 by fle-blay          #+#    #+#             */
/*   Updated: 2022/01/27 10:09:06 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin2(char const *s1, char const *s2, char const *s3)
{
	char	*join;
	int		i;

	if (! s1 || ! s2 || !s3)
		return (NULL);
	join = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + ft_strlen(s3) + 1)
			* sizeof(char));
	if (! join)
		return (NULL);
	i = -1;
	while (s1[++i])
		join[i] = s1[i];
	i = -1;
	while (s2[++i])
		join[ft_strlen(s1) + i] = s2[i];
	i = -1;
	while (s3[++i])
		join[ft_strlen(s1) + ft_strlen(s2) + i] = s3[i];
	join[ft_strlen(s1) + ft_strlen(s2) + i] = '\0';
	return (join);
}
