/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:11:02 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/24 14:43:20 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	garbage_stradd(t_list *garbage, char **str)
{
	int	i;

	i = 0;
	while (str[i] != 0)
	{
		dump_add(str[i], garbage);
		i++;
	}
	dump_add(str[i], garbage);
}

void	execution(char *cmd, char **envp, t_list *garbage)
{
	char	**path;
	char	**args;
	int		exec;

	path = split_path(envp);
int i = 0;
while (path[i] != 0)
{
	dprintf(2, "PATH == %s\n", path[i]);
	i++;
}
	args = ft_split(cmd, ' ');
	dump_add(path, garbage);
	garbage_stradd(garbage, path);
	dump_add(args, garbage);
	garbage_stradd(garbage, args);
	while (*path != NULL)
	{
		exec = execve(*path, args, envp);
		path++;
	}
	if (exec == -1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found!\n", 2);
	}
}
