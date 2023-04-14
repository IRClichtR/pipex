/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:31:53 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 12:31:55 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	beg;
	int		end;

	if (!s1 || !set)
		return (NULL);
	beg = 0;
	end = ft_strlen(s1);
	while (s1[beg] && ft_strchr(set, s1[beg]))
		beg++;
	while (end >= 0 && ft_strchr(set, s1[end - 1]))
		end--;
	return (ft_substr(s1, beg, (end - beg)));
}
