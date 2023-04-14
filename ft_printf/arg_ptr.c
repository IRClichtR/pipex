/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_ptr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:27:16 by ftuernal          #+#    #+#             */
/*   Updated: 2022/12/27 13:28:50 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_hex(unsigned long long nbr)
{
	char			*hexa_base;

	hexa_base = "0123456789abcdef";
	if (nbr >= 16)
		print_hex(nbr / 16);
	ft_putchar_fd((hexa_base[nbr % 16]), 1);
}

static int	ptr_size(unsigned long long dec_ptr)
{
	int					count;

	count = 0;
	while (dec_ptr > 0)
	{
		dec_ptr /= 16;
		count++;
	}
	return (count);
}

int	arg_ptr(void *ptr)
{
	unsigned long long	dec_ptr;
	int					bytes;

	if (!ptr)
	{
		bytes = 5;
		ft_putstr_fd("(nil)", 1);
		return (bytes);
	}
	dec_ptr = (unsigned long long) ptr;
	ft_putstr_fd("0x", 1);
	bytes = 2;
	print_hex(dec_ptr);
	return (bytes += ptr_size(dec_ptr));
}
