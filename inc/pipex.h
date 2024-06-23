/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 06:42:14 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/02/27 13:41:24 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <libft.h>
# include <stdio.h>

char	*ft_find_path(char **envp, char *cmd);
void	ft_exec_proc(char *cmd, char **envp);
int		ft_in_process(int fds[2], char *infile, char *cmd, char **envp);
int		ft_out_process(int fds[2], char *outfile, char *cmd, char **envp);
void	ft_puterror(char *str, int error);

#endif
