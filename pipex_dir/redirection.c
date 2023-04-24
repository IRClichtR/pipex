/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirection.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:33:30 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/24 11:04:41 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	do_parent(int id, int *fd, t_list *garbage)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	waitpid(id, NULL, 0);
	dump_del(garbage);
}

void	redirection(int infile, char *cmd, char **envp, t_list *garbage)
{
	pid_t	id;
	int		fd[2];

	if (pipe(fd) == -1)
	{
		ft_putstr_fd("ERROR pipe failed\n", 2);
		return ;
	}
	id = fork();
	if (id < 0){
		dprintf(2, "id is < 0!\n");
	}
	if (id == 0)
	{
		close(fd[0]);
		dup2(fd[1], STDOUT_FILENO);
		if (infile == STDIN_FILENO)
			exit(1);
		else
			execution(cmd, envp, garbage);
	}
	else
		do_parent(id, fd, garbage);
}
