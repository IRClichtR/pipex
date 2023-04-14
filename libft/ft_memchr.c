/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:21:03 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/24 13:32:32 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)s;
	if (c == 0 && n == 0)
		return (NULL);
	while (i < n)
	{
		if ((unsigned char)str[i] == (unsigned char)c)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
