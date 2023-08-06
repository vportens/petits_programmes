/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 11:58:27 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/10 14:54:26 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlst;
	t_list	*newstart;

	if (! (*f))
		return (lst);
	newstart = NULL;
	if (! lst)
		return (NULL);
	newlst = ft_lstnew((*f)(lst->content));
	if (! newlst)
		return (NULL);
	newstart = newlst;
	while (lst->next)
	{
		newlst->next = ft_lstnew((*f)(lst->next->content));
		if (! newlst->next)
		{
			ft_lstclear(&newstart, del);
			return (NULL);
		}
		newlst = newlst->next;
		lst = lst->next;
	}
	return (newstart);
}
