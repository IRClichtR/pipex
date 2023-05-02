/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_path.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/02 14:52:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/02 18:57:49 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**create_path(char **envp)
{
	char	*strdup_path;
	char	**split_path;
	char	**comp_path;

	strdup_path = copy_path(envp);
	split_path = ft_split(strdup_path, ':');
	//free(copy_path);
	comp_path = loop_joinf(split_path, "/");
	return (comp_path);
}
