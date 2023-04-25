/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:47:22 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/25 17:34:35 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	local_free(char **paths)
{
	int	i;

	i = get_len(paths);
	while(i >= 0)
	{
		if (paths[i] != 0)
			free(paths[i]);
		paths = NULL;
		i--;
	}
	free(paths);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*individual_path;
	int		i;

	paths = complete_paths_syntax(envp);
	i = 0;
	while (paths[i] != 0)
	{
		individual_path = ft_strjoin(paths[i], cmd);
		free(paths[i]);
		if (access(individual_path, F_OK) == 0)
		{
			local_free(paths);	
			return (individual_path);
		}
		i++;
	}
	return (0);
}
