/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:33:35 by ftuernal          #+#    #+#             */
/*   Updated: 2022/12/27 13:34:11 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_hex(int nbr, char xx)
{
	unsigned int	nb;
	char			*hexa_base;

	if (xx == 'X')
		hexa_base = "0123456789ABCDEF";
	else
		hexa_base = "0123456789abcdef";
	nb = nbr;
	if (nb >= 16)
		arg_hex(nb / 16, xx);
	ft_putchar_fd((hexa_base[nb % 16]), 1);
	return (ft_hexasize(nbr));
}
