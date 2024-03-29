/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:34:28 by ftuernal          #+#    #+#             */
/*   Updated: 2023/06/27 16:20:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static int	open_control(char *filename, int std)
{
	if (std == 0 && access(filename, W_OK)!= 0)
		return (-1);
	else if (std == 2 && access(filename, R_OK)!= 0)
		return (-1);
	return (1);
}

static void	print_permerror(void)
{
	perror("Error");
	return ;
}

int	open_file(char *filename, int std)
{
	int	file;

	file = 0;
	if (open_control(filename, std) == -1)
	{
		print_permerror();
		return (-2);
	}
	if (std == 0)
		file = open(filename, O_WRONLY | O_CREAT | O_APPEND | O_CLOEXEC, 0777);
	else if (std == 1)
		file = open(filename, O_WRONLY | O_CREAT | O_TRUNC | O_CLOEXEC, 0777);
	else if (std == 2)
		file = open(filename, O_RDONLY | O_CLOEXEC, 0777);
	if (file == -1)
	{
		ft_putstr_fd(filename, 2);
		perror(" Error: Impossible to open file");
		exit(EXIT_FAILURE);
	}
	return (file);
}
