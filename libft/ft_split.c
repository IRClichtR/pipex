/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:32:32 by ftuernal          #+#    #+#             */
/*   Updated: 2023/02/17 16:11:43 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	str_count(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

static unsigned int	mod_strlen(char const *s, char c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0' && s[i] != c)
		i++;
	return (i);
}

static char	*mod_strdup(const char *s, char c)
{
	size_t	i;
	char	*copy;

	i = 0;
	copy = malloc(sizeof (const char) * mod_strlen(s, c) + 1);
	if (!copy)
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
	{
		copy[i] = s[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**free_if_crash(char **s, int index)
{
	char	**str;

	str = (char **)s;
	if (str[index] == NULL)
	{
		while (index >= 0)
		{
			free(str[index]);
			str[index] = NULL;
			index--;
		}
		free(s);
	}
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char			**super_str;
	unsigned int	i;
	unsigned int	j;
	unsigned int	count;

	count = str_count(s, c);
	i = 0;
	j = 0;
	super_str = malloc(sizeof(char *) * (count + 1));
	if (!super_str)
		return (NULL);
	while (j < count)
	{
		while (s[i] == c && s[i] != '\0')
			i++;
		super_str[j] = mod_strdup(s + i, c);
		if (super_str[j] == NULL)
			return (free_if_crash(super_str, i));
		while (s[i] != c && s[i] != '\0')
			i++;
		j++;
	}
	super_str[j] = NULL;
	return (super_str);
}
