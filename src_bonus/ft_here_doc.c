/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_here_doc.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 15:33:32 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/12/14 16:36:48 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex_bonus.h>

void	ft_here_doc(int fds[2], char *limiter)
{
	char	*line;
	char	*check;

	check = ft_strjoin(limiter, "\n");
	while (1)
	{
		write(1, "heredoc> ", 9);
		line = get_next_line(0);
		if (!ft_strncmp(line, check, ft_strlen(line)) && line)
			break ;
		write(fds[1], line, ft_strlen(line));
		free(line);
	}
	free(line);
	free(check);
}
