/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:37:05 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 12:37:35 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f) (unsigned int, char))
{
	char			*str_res;
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	str_res = malloc (sizeof(char) * ft_strlen(s) + 1);
	if (str_res == NULL)
	{
		free(str_res);
		return (NULL);
	}
	while (s[i] != '\0')
	{
		str_res[i] = f(i, (char)s[i]);
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}
