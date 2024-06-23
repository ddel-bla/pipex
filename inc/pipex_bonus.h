/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/03 06:41:28 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/21 20:01:05 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <fcntl.h>
# include <sys/wait.h>
# include <errno.h>
# include <libft.h>
# include <stdio.h>

void	ft_puterror(char *str, int error);
char	*ft_find_path(char **envp, char *cmd);
void	ft_exec_proc(char *cmd, char **envp);
int		ft_in_process(char **av);
void	ft_mid_process(char *cmd, char **envp);
int		ft_out_process(char *outfile, char *cmd, char **envp, int mode);
void	ft_here_doc(int fds[2], char *limiter);

#endif
