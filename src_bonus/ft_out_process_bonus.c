/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_process_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:31:42 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/21 18:42:33 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	ft_out_process(char *outfile, char *cmd, char **envp, int mode)
{
	int		fd;
	int		pid;

	pid = fork();
	if (pid == -1)
		ft_puterror("Fork Error ", -1);
	if (pid == 0)
	{
		if (mode)
			fd = open(outfile, O_CREAT | O_WRONLY | O_APPEND, 0644);
		else
			fd = open(outfile, O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd == -1)
			ft_puterror("Outfile Error ", -1);
		dup2(fd, STDOUT_FILENO);
		close(fd);
		ft_exec_proc(cmd, envp);
	}
	return (pid);
}
