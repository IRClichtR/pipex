/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:26:23 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/26 17:56:27 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_child(char **argv, char **envp, int *fd)
{
	int	infile;
	int	duped_fdout;
	int	duped_infile;

	infile = open_file(argv[1], 2);
	if (infile < 0)
	{
		close(fd[0]);
		close(fd[1]);
		exit(1);
	}
	duped_fdout = dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	duped_infile = dup2(infile, STDIN_FILENO);
	close(fd[0]);
	close(infile);
	if (argv[2][0] != 0)
		execute(argv[2], envp);
	close(duped_infile);
	close(duped_fdout);
	exit(1);
}
