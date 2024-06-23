/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec_proc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 13:08:39 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/22 03:54:34 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	ft_exec_proc(char *cmd, char **envp)
{
	char	*path;
	char	**args;
	char	*prog;

	path = ft_find_path(envp, cmd);
	if (ft_strlen(path))
		prog = path;
	else
		prog = ft_substr(cmd, 0, ft_strlenchr(cmd, 32));
	args = ft_split(cmd, 32);
	execve(prog, args, envp);
	ft_puterror("Command failed ", 127);
}
