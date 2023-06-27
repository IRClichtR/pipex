/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collect_fd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:29:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/27 15:29:45 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	collect_fd(t_list *fd_collector, int fd)
{
	void	*content;
	t_list	*new;

	content = &fd;
	new = ft_lstnew(content);
	if (!new)
		return ;
	ft_lstadd_back(&fd_collector, new);
}
