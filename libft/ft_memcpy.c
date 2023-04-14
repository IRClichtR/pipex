/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 11:58:27 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 11:58:29 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned int	i;
	char			*dest_cast;
	char			*src_cast;

	i = 0;
	dest_cast = (char *)dest;
	src_cast = (char *)src;
	while (i < n)
	{
		if (&dest_cast[i] == &src_cast[i])
			return (NULL);
		i++;
	}
	i = 0;
	while (i < n)
	{
		dest_cast[i] = src_cast[i];
		i++;
	}
	return (dest);
}
