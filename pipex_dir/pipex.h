/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftuernal <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 16:08:40 by ftuernal          #+#    #+#             */
/*   Updated: 2023/04/25 17:20:36 by ftuernal         ###   ########.fr       */
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

char	**complete_paths_syntax(char **envp);
void	do_child(char **argv, char **envp, int *fd);
void	do_parent(char **argv, char **envp, int *fd);
void	execute(char *arg, char **envp);
char	*find_path(char *cmd, char **envp);
int		open_file(char *filename, int std);
char	**search_paths(char **envp);
#endif
