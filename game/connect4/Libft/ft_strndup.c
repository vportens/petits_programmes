/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:08:33 by fle-blay          #+#    #+#             */
/*   Updated: 2022/05/16 18:14:32 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *str, size_t len_max)
{
	char	*new_str;
	int		len_str;
	size_t	i;

	len_str = ft_strnlen(str, len_max);
	new_str = malloc((len_str + 1) * sizeof(char));
	if (!new_str)
		return (NULL);
	new_str[len_str] = '\0';
	i = 0;
	while (i < len_max && str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	return (new_str);
}
