/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:44:14 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 13:48:42 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last_ad;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	last_ad = ft_lstlast(*lst);
	last_ad->next = new;
}
