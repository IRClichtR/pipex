/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:08:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/05/03 11:15:46 by ftuernal         ###   ########.fr       */
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
char	**create_path(char **envp);
void	do_child(char **argv, char **envp, int *fd);
void	do_parent(char **argv, char **envp, int *fd);
void	execute(char *arg, char **envp);
char	*find_path(char *cmd, char **envp);
char	**loop_joinf(char **split_path, char *charset);
int		open_file(char *filename, int std);
#endif
