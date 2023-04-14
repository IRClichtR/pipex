/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:23:56 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 12:24:24 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*big_temp;
	char	*little_temp;

	i = 0;
	big_temp = (char *)big;
	little_temp = (char *)little;
	if (little_temp[i] == '\0')
		return (big_temp);
	while (i < len && big_temp[i] != '\0')
	{
		j = 0;
		while (i + j < len && big_temp[i + j] == little_temp[j]
			&& little_temp[j] != '\0')
			j++;
		if (little_temp[j] == '\0')
			return ((char *)big + i);
		i++;
	}
	return (NULL);
}
