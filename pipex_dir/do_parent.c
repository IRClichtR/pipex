/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:29:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/03 14:55:26 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_parent(char **argv, char **envp, int *fd)
{
	int	outfile;
	int	duped_fdin;
	int	duped_outfile;

	outfile = open_file(argv[4], 1);
	if (outfile == -1)
	{
		close(fd[0]);
		close(fd[1]);
		ft_putstr_fd(argv[4], 2);
		perror(" : open() error\n");
		exit(errno);
	}
	duped_fdin = dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	duped_outfile = dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(outfile);
	execute(argv[3], envp);
	close(duped_fdin);
	close(duped_outfile);
}
