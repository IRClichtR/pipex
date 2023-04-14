/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 12:34:39 by ftuernal          #+#    #+#             */
/*   Updated: 2022/11/23 18:06:50 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	len_nbr(int n)
{
	unsigned int	len;
	unsigned int	nb;

	len = 0;
	if (n < 0)
	{
		nb = -n;
		len += 1;
	}
	else if (n == 0)
		return (1);
	else
		nb = n;
	while (nb > 0)
	{
		len++;
		nb /= 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char			*nbr;
	int				len;
	unsigned int	nb;

	if (n == 0)
		return (ft_strdup("0"));
	len = len_nbr(n);
	nbr = malloc(sizeof(char) * len + 1);
	if (nbr == NULL)
		return (NULL);
	if (n < 0)
	{
		nbr[0] = '-';
		nb = -n;
	}
	else
		nb = n;
	nbr[len] = '\0';
	len -= 1;
	while (nb > 0)
	{
		nbr[len--] = (nb % 10) + '0';
		nb /= 10;
	}
	return (nbr);
}
