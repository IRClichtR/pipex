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
	char	**args;

	if (ac > 4)
	{
		args = super_strdup(args, ac - 1);
		if (args == 0)
		{
			ft_putstr_fd(2, "Error: Args String Alloc failed\n");
			return (1);
		}
		success = pipex(args, envp);
		if (success == -1)
		{
			free_whatever(args);
			return (1);
		}
	}
	else
		ft_putstr_fd("ARG_ERROR: Insufficient arg nbr!\n", 2);
	return (0);
}
