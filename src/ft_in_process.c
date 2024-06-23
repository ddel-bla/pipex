/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_process.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:08:24 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/21 19:09:28 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	ft_in_process(int fds[2], char *infile, char *cmd, char **envp)
{
	int		fd;
	int		pid;

	pid = fork();
	if (pid == -1)
		ft_puterror("In process, Fork Error ", -1);
	else if (pid == 0)
	{
		close(fds[0]);
		fd = open(infile, O_RDONLY);
		if (fd == -1)
			ft_puterror("Infile Error ", 0);
		dup2(fds[1], STDOUT_FILENO);
		close(fds[1]);
		dup2(fd, STDIN_FILENO);
		close(fd);
		ft_exec_proc(cmd, envp);
	}
	return (pid);
}
