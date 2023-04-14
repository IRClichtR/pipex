/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:30:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/02/16 18:19:23 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>
#include <stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str1;
	char			*str2;
	char			*cat_str;
	unsigned int	i;
	unsigned int	j;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = 0;
	j = 0;
	cat_str = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!cat_str)
		return (NULL);
	while (str1[i] != '\0')
	{
		cat_str[i] = str1[i];
		i++;
	}
	while (str2[j] != '\0')
	{
		cat_str[i + j] = str2[j];
		j++;
	}
	cat_str[i + j] = '\0';
	return (cat_str);
}
