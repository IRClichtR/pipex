/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:05:48 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/13 12:19:22 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipex(char **args, int ac, char **envp)
{
	int	infile;
	int	outfile;
	int	i;

	infile = open_file(args[1], 0);
	outfile = open_file(args[get_len(args) - 1], 1);
	if (infile == -1 || outfile == -1)
		return (-1);
	dup2(infile, STDIN);
	dup2(outfile, STDOUT);
	redirection(infile, args[2], envp);
	i = 0;
	while (++i < ac - 2)
		redirection(1, args[i], envp);
	execution(av[2], envp);
	return (-1);
}
