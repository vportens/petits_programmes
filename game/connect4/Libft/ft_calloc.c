/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 08:32:15 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/08 09:43:33 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void			*ptr;
	long long int	memsize;

	if (! nmemb || ! size)
		return (malloc(0));
	memsize = nmemb * size;
	if (memsize / nmemb != size)
		return (NULL);
	ptr = (void *)malloc(memsize);
	if (! ptr)
		return (NULL);
	ft_bzero(ptr, memsize);
	return (ptr);
}
