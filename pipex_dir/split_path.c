/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_path.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 11:47:06 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/13 11:47:14 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_path(char **envp)
{
	char	**res;
	char	*path;

	path = copy_path(envp);
	if (path == NULL)
		return (NULL);
	res = ft_split(path, ':');
	if (res == NULL)
	{
		free(path);
		return (NULL);
	}
	free(path);
	return (res);
}
