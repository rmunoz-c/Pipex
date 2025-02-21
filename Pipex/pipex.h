/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmunoz-c <rmunoz-c@student.42madrid.com>   #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-12 16:01:26 by rmunoz-c          #+#    #+#             */
/*   Updated: 2024-12-12 16:01:26 by rmunoz-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
# include <stdio.h>
# include <wait.h>
# include <unistd.h>
# include <fcntl.h>

//pipex.c
int		open_file(char *file, size_t b);
void	exec(char *cmd, char **envp);
void	child_process(char **argv, int *pipe_fd, char **envp);
int		main(int argc, char **argv, char **envp);

//pipex_utils.c;
char	*ft_getenv(const char *name, char **envp);
char	*ft_path(char *cmd, char **envp);

#endif