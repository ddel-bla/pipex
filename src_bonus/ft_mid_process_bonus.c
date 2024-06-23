/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mid_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:53 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/20 12:19:01 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	ft_mid_process(char *cmd, char **envp)
{
	int		fds[2];
	int		pid;

	if (pipe(fds) == -1)
		ft_puterror("Pipe Error ", -1);
	pid = fork();
	if (pid == -1)
		ft_puterror("Fork Error ", -1);
	if (pid == 0)
	{
		close(fds[0]);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		ft_exec_proc(cmd, envp);
	}
	else
	{
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
	}
}
