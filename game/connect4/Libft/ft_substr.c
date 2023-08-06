/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 11:30:42 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/23 10:54:43 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	unsigned int	lensub;
	char			*subs;

	i = 0;
	if (! s)
		return (NULL);
	subs = NULL;
	if (start > ft_strlen(s))
		lensub = 0;
	else if (ft_strlen(s) - start < len)
		lensub = ft_strlen(s) - start;
	else
		lensub = len;
	subs = (char *)malloc((lensub + 1) * sizeof(char));
	if (! subs)
		return (NULL);
	while (i < lensub)
	{
		subs[i] = s[start + i];
		i++;
	}
	subs[i] = '\0';
	return (subs);
}
