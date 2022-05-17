/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memalloc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: viporten <viporten@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/23 20:50:16 by laclide           #+#    #+#             */
/*   Updated: 2022/03/20 18:58:25 by viporten         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

void	*ft_memalloc(size_t size)
{
	void	*result;

	result = malloc(size + 1);
	if (result != NULL)
	{
		ft_memset(result, '\0', size);
	}
	return (result);
}
