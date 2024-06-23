/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 06:39:01 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/22 02:52:47 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int argc, char **argv, char **envp)
{
	int	fds[2];
	int	pid[2];
	int	status;

	status = 0;
	if (argc != 5)
	{
		ft_putendl_fd("Format: ./pipex filein cmd1 cmd2 fileout", 2);
		return (1);
	}
	if (pipe(fds) == -1)
		ft_puterror("Pipe Error ", -1);
	pid[0] = ft_in_process(fds, argv[1], argv[2], envp);
	pid[1] = ft_out_process(fds, argv[4], argv[3], envp);
	close(fds[0]);
	close(fds[1]);
	waitpid(pid[0], NULL, 0);
	waitpid(pid[1], &status, 0);
	return (status);
}
