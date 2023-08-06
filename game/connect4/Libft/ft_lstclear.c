/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 09:09:39 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/23 10:52:54 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*index;

	index = NULL;
	if (*lst == NULL)
		return ;
	while ((*lst)->next)
	{
		index = *lst;
		*lst = (*lst)->next;
		ft_lstdelone(index, del);
		index = NULL;
	}
	ft_lstdelone(*lst, del);
	*lst = NULL;
}
