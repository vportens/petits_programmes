/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:35:44 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/17 15:43:28 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_destoverlap(void *dest, const void *src, size_t n)
{
	long unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src + i == dest)
			return (1);
		i++;
	}
	return (0);
}

static void	*ft_revmemcpy(void *dest, const void *src, size_t n)
{
	if (dest == NULL || src == NULL)
		return (NULL);
	while (n > 0)
	{
		((char *) dest)[n - 1] = ((char *) src)[n - 1];
		n--;
	}
	return (dest);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	if (ft_destoverlap(dest, src, n))
		return (ft_revmemcpy(dest, src, n));
	else
		return (ft_memcpy(dest, src, n));
}
