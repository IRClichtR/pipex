/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:25:27 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/24 17:25:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	**split_cmd(char **av, char *cmd)
{
	char	**argument;

	argument = ft_calloc(1, sizeof(char *));
	*argument = ft_strdup(av[0]);
	if (argument == NULL || argument[0] == NULL)
		return (NULL);
	argument + 1 = ft_split(cmd);
	return (argument);
}
