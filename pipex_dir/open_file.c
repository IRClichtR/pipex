/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:34:28 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/02 10:44:24 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	open_file(char *filename, int std)
{
	int	file;

	file = 0;
	if (std == 0)
		file = open(filename, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
	else if (std == 1)
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	else if (std == 2)
		file = open(filename, O_RDONLY | O_CREAT | O_CLOEXEC, 0777);
	if (file == -1)
	{
		ft_putstr_fd(filename, 2);
		perror(" Error: Impossible to open file\n");
		exit(EXIT_FAILURE);
	}
	return (file);
}
