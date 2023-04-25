/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:04:06 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/25 17:17:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**search_paths(char **envp)
{
	int		i;
	char	**partial_paths;

	i = 0;
	while (ft_strncmp(envp[i], "PATH", 4) != 0)
		i++;
	partial_paths = ft_split(envp[i] + 5, ':');
	return (partial_paths);
}
