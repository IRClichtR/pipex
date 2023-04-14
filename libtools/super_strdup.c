/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   super_strdup.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 19:46:53 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/07 19:46:55 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtools.h"

char	**super_strdup(char **av, int ac)
{
	char	**arg;
	int		i;

	arg = ft_calloc(ac, sizeof(char *));
	if (!arg)
		return (NULL);
	i = 0;
	while (av[i] != 0)
	{
		arg[i] = ft_strdup(av[i]);
		if (av[i] = NULL)
		{
			free_whatever("s", av);
			return (NULL);
		}
		i++;
	}
	arg[i] = '\0';
	return (arg);
}
