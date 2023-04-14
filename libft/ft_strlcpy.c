/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:15:29 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 12:15:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	char	*sc;

	i = 0;
	sc = (char *)src;
	if (size > 0)
	{
		while (sc[i] && i < size - 1)
		{
			dest[i] = sc[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (sc[i])
		i++;
	return (i);
}
