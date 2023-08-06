/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fle-blay <fle-blay@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 18:36:18 by fle-blay          #+#    #+#             */
/*   Updated: 2021/11/09 19:32:38 by fle-blay         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*index;

	if (*alst == NULL)
	{
		*alst = new;
		return ;
	}
	index = *alst;
	while (index->next)
		index = index->next;
	index->next = new;
}
