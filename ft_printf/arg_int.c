/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_int.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:32:20 by ftuernal          #+#    #+#             */
/*   Updated: 2022/12/27 13:32:33 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_int(int i)
{
	unsigned int	nbr;
	int				bytes;

	bytes = 0;
	if (i < 0)
	{
		nbr = -i;
		bytes = 1;
		ft_putchar_fd('-', 1);
	}
	else
		nbr = i;
	if (nbr > 9)
		arg_int(nbr / 10);
	ft_putchar_fd((nbr % 10 + 48), 1);
	return (bytes += ft_nbrsize(nbr));
}
