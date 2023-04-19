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
# include "../libtools/libtools.h"
# include "../ft_printf/ft_printf.h"
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <errno.h>

char	*copy_path(char **envp);
void	execution(char *cmd, char **envp, t_list *garbage);
int		open_file(char *filename, int mode);
int		pipex(char **args, int ac, char **envp);
void	redirection(int infile, char *cmd, char **envp, t_list *garbage);
char	**split_path(char **envp);
#endif
