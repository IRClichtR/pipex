/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/27 13:35:50 by ftuernal          #+#    #+#             */
/*   Updated: 2023/03/29 16:14:45 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "../libft/libft.h"
# include <stdio.h>

int	arg_char(char c);
int	arg_str(char *str);
int	arg_ptr(void *ptr);
int	arg_int(int i);
int	arg_uint(unsigned int i);
int	arg_hex(int i, char xx);
int	ft_printf(const char *str, ...);
int	ft_nbrsize(unsigned int nbr);
int	ft_hexasize(int nbr);
#endif
