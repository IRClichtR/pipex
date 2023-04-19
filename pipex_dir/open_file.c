/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:56:27 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/12 13:58:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static void	print_accerror(char *filename)
{
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" : ERROR! no file or dir with that name\n", 2);	
}

static void	print_openerror(char *filename)
{
	ft_putstr_fd(filename, 2);
	ft_putstr_fd(" : ERROR! Fail in opening the file\n", 2);	
}

int	open_file(char *filename, int mode)
{
	int	acc;
	int	open_fd;

	if (mode == 0)
	{
		acc = access(filename, F_OK);
		if (acc == -1)
		{
			print_accerror(filename);
			return (-1);
		}
		open_fd = open(filename, O_RDONLY);
	}
	else
		open_fd = open(filename, O_WRONLY);
	if (open_fd == -1)
	{	
		print_openerror(filename);
		return (-1);
	}
	return (open_fd);
}
