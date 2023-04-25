/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complete_paths_syntax.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:16:54 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/25 17:24:36 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**complete_paths_syntax(char **envp)
{
	char 	**comp_path;
	char 	**partial_path;
	int		i;

	i = 0;
	partial_path = search_paths(envp);
	comp_path = ft_calloc(get_len(partial_path) + 1, sizeof(char *));
	while (partial_path[i] != 0)
	{
		comp_path[i] = ft_strjoin(partial_path[i], "/");
		free(partial_path[i]);
		partial_path[i] = 0;
		i++;
	}
	free(partial_path[i]);
	free(partial_path);
	comp_path[i] = 0;
	return (comp_path);
}
