/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 09:35:41 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/16 18:15:28 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	long unsigned int	i;
	long unsigned int	lendst;
	long unsigned int	lensrc;

	i = 0;
	lendst = ft_strnlen(dst, size);
	lensrc = ft_strlen(src);
	if (size <= lendst)
		return (size + lensrc);
	while (lendst + i < size - 1 && src[i])
	{
		dst[lendst + i] = src[i];
		i++;
	}
	dst[lendst + i] = '\0';
	return (lendst + lensrc);
}
