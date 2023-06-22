/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_path.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:47:22 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/22 12:55:18 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	add_str_to_dump(char **paths, t_list *dump)
{
	int		i;

	i = 0;
	dump_add(paths, dump);
	while (paths[i] != 0)
	{
		dump_add(paths[i], dump);
		i++;
	}
	dump_add(paths[i], dump);
}

char	*find_path(char *cmd, char **envp)
{
	char	**paths;
	char	*individual_path;
	t_list	*dump;
	int		i;

	paths = create_path(envp);
	dump = ft_calloc(1, sizeof(t_list));
	add_str_to_dump(paths, dump);
	i = 0;
	while (paths[i] != 0)
	{
		individual_path = ft_strjoin(paths[i], cmd);
		if (access(individual_path, X_OK) == 0)
		{
			dump_del(dump);
			return (individual_path);
		}
		dump_add(individual_path, dump);
		i++;
	}
	dump_del(dump);
	return (0);
}
