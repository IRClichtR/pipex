/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:31:08 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/03 15:42:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	add_ptstr_to_dump(char **str, t_list *dump)
{
	int	i;

	i = 0;
	dump_add(str, dump);
	while (str[i] != NULL)
	{
		dump_add(str[i], dump);
		i++;
	}
	dump_add(str[i], dump);
}

void	execute(char *arg, char **envp)
{
	char	**cmd;
	int		exec;
	char	*path;
	t_list	*garbage;

	garbage = ft_calloc(1, sizeof(t_list));
	cmd = ft_split(arg, ' ');
	path = find_path(cmd[0], envp);
	dump_add(path, garbage);
	add_ptstr_to_dump(cmd, garbage);
	if (access(cmd[0], F_OK) == -1)
	{
		dump_del(garbage);
		perror("Error: Command not found");
		exit(errno);
	}
	exec = execve(path, cmd, envp);
	if (exec == -1)
		perror("Execve error: ");
	exit(errno);
}
