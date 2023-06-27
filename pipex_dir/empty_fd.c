/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   empty_fd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 15:34:12 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/27 15:50:54 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	empty_fd(t_list *fd_collector)
{
	int	*fd;

	if (fd_collector == NULL)
		return ;
	else
	{
		empty_fd(fd_collector->next);
		fd = (int *)fd_collector->content;
		close(*fd);
		free(fd_collector);
	}
}
