/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 16:21:45 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/06/23 13:47:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

int	main(int ac, char **av, char **envp)
{
	int		start;
	int		mode;
	int		status;
	int		pid;

	if (ac < 5)
	{
		ft_putendl_fd("Format: ./pipex filein cmd1 cmd2 cmdN ... fileout", 2);
		ft_putendl_fd("Format: ./pipex here_doc LIMITER cmdN ... fileout", 2);
		return (1);
	}
	mode = ft_in_process(av);
	start = 2 + mode;
	while (start < ac - 2)
		ft_mid_process(av[start++], envp);
	pid = ft_out_process(av[ac - 1], av[ac - 2], envp, mode);
	status = 0;
	waitpid(pid, &status, 0);
	while (mode++ < ac - 4)
		wait(NULL);
	return (i(status));
}
