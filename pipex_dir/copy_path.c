/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:33:33 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/13 11:34:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*copy_path(char **envp)
{
	int		i;
	char	*path_copy;

	i = 0;
	while (envp[i] != 0)
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
		{
			path_copy = ft_strdup(envp[i] + 5);
			if (!path_copy)
				return (NULL);
			return (path_copy);
		}
		i++;
	}
	return (NULL);
}
