/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_in_process.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:32:11 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/15 15:52:46 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	ft_in_process(char **av)
{
	int	fd;
	int	fds[2];

	if (!ft_strncmp(av[1], "here_doc", 9))
	{
		if (pipe(fds) == -1)
			ft_puterror("Pipe Error ", -1);
		ft_here_doc(fds, av[2]);
		close(fds[1]);
		dup2(fds[0], STDIN_FILENO);
		close(fds[0]);
		return (1);
	}
	else
	{
		fd = open(av[1], O_RDONLY);
		if (fd == -1)
			ft_puterror("Infile Error ", 0);
		dup2(fd, STDIN_FILENO);
		close(fd);
		return (0);
	}
}
