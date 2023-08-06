/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 15:17:08 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/09 15:26:08 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*elem;

	elem = NULL;
	elem = (t_list *)malloc(sizeof(t_list));
	if (! elem)
		return (NULL);
	elem->content = content;
	elem->next = NULL;
	return (elem);
}
