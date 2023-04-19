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
	t_list	*garbage;
	int		i;

	arg = ft_calloc(ac, sizeof(char *));
	garbage = ft_calloc(1, sizeof(t_list));
	if (!arg || !garbage)
		return (NULL);
	i = 0;
	dump_add(arg, garbage);
	while (av[i] != 0)
	{
		arg[i] = ft_strdup(av[i]);
		if (av[i] == NULL)
		{
			dump_del(garbage);
			return (NULL);
		}
		dump_add(arg[i], garbage);
		i++;
	}
	arg[i] = 0;
	return (arg);
}
