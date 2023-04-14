/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:08:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/04 16:42:31 by ftuernal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../GNL/get_next_line.h"
# include "../ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
//# include <process.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <errno.h>

void	do_child(int file, char *cmd1);
void	do_parent(int file, char *cmd2);
int		is_cmd(char *cmd1, char *cmd2);
void	pipex(int *files, char *cmd1, char *cmd2);
int		set_args(int ac, char **argv, char **envt);
#endif
