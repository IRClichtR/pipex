/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:31:08 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/21 19:12:30 by ftuernal         ###   ########.fr       */
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

static void	error_execute(t_list *garbage)
{
	ft_putstr_fd("In execute() function: ", 2);
	ft_putstr_fd("command not found\n", 2);
	dump_del(garbage);
}

void	execute(char *arg, char **envp)
{
	char	**cmd;
	char	*path;
	t_list	*garbage;

	cmd = ft_split(arg, ' ');
	if (!cmd)
		return ;
	garbage = ft_calloc(1, sizeof(t_list));
	path = find_path(cmd[0], envp);
	if (path == NULL)
	{
		error_execute(garbage);
		exit(127);
	}
	dump_add(path, garbage);
	add_ptstr_to_dump(cmd, garbage);
	execve(path, cmd, envp);
	perror("Execve error: ");
	dump_del(garbage);
	exit(1);
}
