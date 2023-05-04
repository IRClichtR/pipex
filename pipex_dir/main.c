/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:18:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/04 12:06:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid;

	if (ac == 5)
	{
		if (pipe(fd) == -1)
		{
			perror("Error: pipe failure!\n");
			exit(127);
		}
		pid = fork();
		if (pid == 0)
			do_child(av, envp, fd);
		waitpid(pid, NULL, 0);
		do_parent(av, envp, fd);
	}
	else
	{
		ft_putstr_fd("Error: Invalid arguments number!\n", 2);
		ft_putstr_fd("Enter 4 valid arguments <INF> <CMD1> <CMD2> <OUT>", 2);
		exit(7);
	}
	return (0);
}
