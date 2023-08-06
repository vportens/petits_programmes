/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 12:26:43 by fle-blay          #+#    #+#             */
/*   Updated: 2022/02/03 12:28:42 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	long unsigned int	i;
	long unsigned int	j;

	if (little[0] == '\0')
		return ((char *)big);
	i = 0;
	while (big[i])
	{
		if (big[i] == little[0])
		{
			j = 0;
			while (big[i + j] && little[j])
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
