/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:14:08 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 12:14:10 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	size;
	char	*sc;
	char	*dst;

	dst = (char *)dest;
	sc = (char *)src;
	size = 0;
	if (sc < dst)
	{
		size = n;
		while (size > 0)
		{
			size--;
			dst[size] = sc[size];
		}
	}
	else
	{
		while (size < n)
		{
			dst[size] = sc [size];
			size++;
		}
	}
	return (dest);
}	
