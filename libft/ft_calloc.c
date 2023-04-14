/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/28 09:34:14 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/28 09:35:36 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*array;

	if (nmemb == 0 || size == 0)
		return (malloc(0));
	if (nmemb > (SIZE_MAX) / size)
		return (NULL);
	array = malloc(size * nmemb);
	if (array == NULL)
		return (NULL);
	ft_memset(array, 0, nmemb * size);
	return (array);
}
