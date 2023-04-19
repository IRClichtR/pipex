/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 14:51:34 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/12 18:28:52 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **envp)
{
	int	success;

	if (ac > 4)
	{
		success = pipex(av, ac, envp);
		if (success == -1)
		{
			ft_putstr_fd("Error: Pipex failed\n", 2);
			return (1);
		}
	}
	else
		ft_putstr_fd("ARG_ERROR: Insufficient arg nbr!\n", 2);
	return (0);
}
