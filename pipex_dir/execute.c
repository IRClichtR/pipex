/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:31:08 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/25 17:37:53 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	free_all_str(char **cmd)
{
	int	i;

	i = get_len(cmd);
	while (i >= 0)
	{
		if (cmd[i] != 0)
			free(cmd[i]);
		cmd[i] = NULL;
		i--;
	}
	free(cmd);
	cmd = NULL;
}

void	execute(char *arg, char **envp)
{
	char	**cmd;
	int		exec;

	cmd = ft_split(arg, ' ');
	exec = execve(find_path(cmd[0], envp), cmd, envp);
	if (exec == -1)
	{
		free_all_str(cmd);
		ft_putstr_fd("Error: execution error!", 2);
		exit(EXIT_FAILURE);
	}
}
