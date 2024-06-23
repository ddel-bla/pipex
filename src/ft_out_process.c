/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:04:14 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/21 19:10:05 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	ft_out_process(int fds[2], char *outfile, char *cmd, char **envp)
{
	int		fd;
	int		pid;

	pid = fork();
	if (pid == -1)
		ft_puterror("Out process, Fork Error ", -1);
	else if (pid == 0)
	{
		close(fds[1]);
		fd = open(outfile, O_CREAT | O_RDWR | O_TRUNC, 0644);
		if (fd == -1)
			ft_puterror("Outfile Error ", -1);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		ft_exec_proc(cmd, envp);
	}
	return (pid);
}
