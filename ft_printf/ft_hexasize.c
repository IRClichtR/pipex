/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexasize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:29:23 by ftuernal          #+#    #+#             */
/*   Updated: 2022/12/27 13:30:12 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hexasize(int nbr)
{
	int				count;
	unsigned int	nb;

	count = 0;
	nb = nbr;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		count++;
	}
	return (count);
}
