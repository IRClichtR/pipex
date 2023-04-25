/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_parent.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:29:44 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/25 17:25:05 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	do_parent(char **argv, char **envp, int *fd)
{
	int	outfile;

	outfile = open_file(argv[4], 1);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(outfile, STDOUT_FILENO);
	close(fd[1]);
	close(outfile);
	execute(argv[3], envp);
}
