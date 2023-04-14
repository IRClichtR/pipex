/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_uint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:32:45 by ftuernal          #+#    #+#             */
/*   Updated: 2022/12/27 13:33:02 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_uint(unsigned int i)
{
	unsigned int	nbr;

	nbr = i;
	if (nbr > 9)
		arg_uint(nbr / 10);
	ft_putchar_fd((nbr % 10 + 48), 1);
	return (ft_nbrsize(i));
}
