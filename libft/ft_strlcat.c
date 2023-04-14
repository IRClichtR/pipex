/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:16:09 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 12:16:35 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dest_len;
	size_t	sc_len;
	char	*sc;

	i = 0;
	sc = (char *)src;
	dest_len = ft_strlen(dest);
	sc_len = ft_strlen(sc);
	if (size == 0 || dest_len >= size)
		return (size + sc_len);
	while (i + dest_len < size - 1 && sc[i] != '\0')
	{
		dest[dest_len + i] = sc[i];
		i++;
	}
	dest[i + dest_len] = '\0';
	return (dest_len + sc_len);
}
