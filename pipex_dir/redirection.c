/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:33:30 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/13 12:19:28 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	do_parent(int id, int *pipe_fd)
{
	close(pipe_fd[1]);
	dup2(pipe_fd[0], STDIN);
	wait_pid(id, NULL, 0);
}

static void	do_child(int id, int *pipe_fd, int infile, char *cmd)
{
}

void	redirection(int infile, char *cmd, char **envp)
{
	pid_t	id;
	int		*pipe_fd[2];
	char	**path;
	char	**args

	if (pipe(pipe_fd) == 0)
	{
		id = fork();
		if (id == 0)
		{
			close(pipe_fd[0]);
			dup2(pipe_fd[1], STDOUT);
			if (infile == STDIN)
				exit(1);
			else
				execution(cmd, envp);
		}
		else
			do_parent(id, pipe_fd);
	}
}
