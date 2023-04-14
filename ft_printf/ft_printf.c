/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:35:03 by ftuernal          #+#    #+#             */
/*   Updated: 2022/12/27 13:37:19 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	put_arg(char c, va_list args)
{
	int	bytes;

	bytes = 0;
	if (c == '%')
	{
		ft_putchar_fd('%', 1);
		bytes += 1;
	}
	else if (c == 'c')
		bytes += arg_char(va_arg(args, int));
	else if (c == 's')
		bytes += arg_str(va_arg(args, char *));
	else if (c == 'p')
		bytes += arg_ptr(va_arg(args, void *));
	else if (c == 'd' || c == 'i')
		bytes += arg_int(va_arg(args, int));
	else if (c == 'u')
		bytes += arg_uint(va_arg(args, unsigned int));
	else if (c == 'x' || c == 'X')
		bytes += arg_hex(va_arg(args, int), c);
	else if (ft_strchr("cspdiuxX%", c) == NULL)
		return (0);
	return (bytes);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	va_start(args, str);
	while (str && str[i] != 0)
	{
		if (str[i] == '%')
		{
			bytes += put_arg(str[i + 1], args);
			i += 1;
		}
		else
		{
			bytes += 1;
			ft_putchar_fd(str[i], 1);
		}
		i++;
	}
	va_end(args);
	return (bytes);
}
