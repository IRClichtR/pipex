/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtools.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 17:27:01 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/13 17:27:03 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBTOOLS_H
# define LIBTOIOLS_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

void    dump_add(void *content, t_list **garbage);
void    dump_del(t_list *garbage);
char	**super_strdup(char **av, int ac);
int		get_len(char **str);
#endif
