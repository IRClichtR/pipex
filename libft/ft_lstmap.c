/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:47:41 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 14:26:16 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, void *(*f) (void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*newcellinlst;

	if (!lst)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newcellinlst = ft_lstnew(f(lst->content));
		if (!newcellinlst)
		{
			ft_lstclear(&newcellinlst, del);
			return (newlist);
		}
		ft_lstadd_back(&newlist, newcellinlst);
		lst = lst->next;
	}
	return (newlist);
}
