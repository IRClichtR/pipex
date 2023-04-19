/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 12:11:02 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/13 12:14:45 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execution(char *cmd, char **envp, t_list *garbage)
{
	char	**path;
	char	**args;
	int		exec;

	path = split_path(envp);
	args = ft_split(cmd, ' ');
	dump_add(path, garbage);
	dump_add(args, garbage);
	while (*path != NULL)
	{
		exec = execve(*path, args, envp);
		args++;
	}
	if (exec == -1)
	{
		ft_putstr_fd(cmd, 2);
		ft_putstr_fd(": command not found!", 2);
	}
}
