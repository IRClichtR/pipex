/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:18:56 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/27 16:03:58 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	display_instructions(void)
{
	ft_putstr_fd("Error: Invalid arguments number!\n", 2);
	ft_putstr_fd("Enter 4 valid arguments <INF> <CMD1> <CMD2> <OUT>", 2);
	exit(7);
}

static void	envp_error(void)
{
	ft_putstr_fd("ERROR: Empty Path\n", 2);
	exit(127);
}

static void	pipe_error(void)
{
	perror("Error: pipe failure!\n");
	exit(127);
}

static void	do_postprocess(int *fd, int pid2, int pid1)
{
//	wait(NULL);
	waitpid(pid1, NULL, WUNTRACED);
	waitpid(pid2, NULL, WUNTRACED);
	waitpid(-1, NULL, 0);
	close(fd[0]);
	close(fd[1]);
}

int	main(int ac, char **av, char **envp)
{
	int	fd[2];
	int	pid1;
	int	pid2;

	if (envp[0] == NULL)
		envp_error();
	if (ac == 5)
	{
		if (pipe(fd) == -1)
			pipe_error();
		pid1 = fork();
		if (pid1 == 0)
			do_child(av, envp, fd);
		pid2 = fork();
		if (pid2 == 0)
			do_parent(av, envp, fd);
		do_postprocess(fd, pid2, pid1);
	}
	else
		display_instructions();
	return (0);
}
