/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/06 10:40:36 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/06 11:46:22 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	long unsigned int	i;
	long unsigned int	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] && little[j] && (i + j) < len)
			{
				if (big[i + j] == little[j])
					j++;
				else
					break ;
			}
			if (j == ft_strlen(little))
				return ((char *)big + i);
		}
		i++;
	}
	return (NULL);
}
