/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:52:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/22 12:54:39 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_path(char **envp)
{
	char	*strdup_path;
	char	**split_path;
	char	**comp_path;

	if (envp == NULL)
	{
		ft_putstr_fd("envp error\n", 2);
		exit(127);
	}
	strdup_path = copy_path(envp);
	split_path = ft_split(strdup_path, ':');
	comp_path = loop_joinf(split_path, "/");
	free(strdup_path);
	return (comp_path);
}
