/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 18:03:55 by ddel-bla          #+#    #+#             */
/*   Updated: 2024/03/22 01:05:31 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void
	ft_free_it(char **tab, char *prog, char *sub)
{
	int	i;

	i = 0;
	free(prog);
	free(sub);
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

static char
	**ft_get_path(char **e)
{
	char	*line;
	char	**tab;

	while (*e && !ft_strnstr(*e, "PATH=", 5))
		e++;
	if (!*e)
		return (NULL);
	line = ft_substr(*e, 5, ft_strlen(*e) - 5);
	tab = ft_split(line, ':');
	free(line);
	return (tab);
}

char	*ft_find_path(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*prog;
	char	*sub;
	int		i;

	paths = ft_get_path(envp);
	if (!paths)
		return (NULL);
	prog = ft_substr(cmd, 0, ft_strlenchr(cmd, 32));
	sub = ft_strjoin("/", prog);
	i = 0;
	while (paths[i])
	{
		cmd_path = ft_strjoin(paths[i], sub);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK))
			break ;
		free(cmd_path);
		i++;
	}
	ft_free_it(paths, prog, sub);
	return (cmd_path);
}
