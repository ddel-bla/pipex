/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:10:20 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int
	ft_find_words(char const *s, char c)
{
	unsigned long	i;
	int				tot;

	i = 0;
	tot = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == 0))
			tot++;
		i++;
	}
	return (tot);
}

static int
	ft_find_word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] != c && s[len] != 0)
		len++;
	return (len);
}

static char
	**ft_free_it(char **tab, unsigned long len)
{
	while (len--)
		free(tab[len]);
	free(tab);
	return (NULL);
}

char
	**ft_split(char const *s, char c)
{
	long int	words;
	long int	i;
	long int	len;
	char		**tab;

	words = ft_find_words(s, c);
	tab = (char **)malloc(sizeof(char *) * (words + 1));
	if (!tab)
		return (0);
	i = 0;
	len = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = ft_find_word_len(s, c);
		tab[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!tab[i])
			return (ft_free_it(tab, i));
		ft_strlcpy(tab[i], s, len + 1);
		s += len;
		i++;
	}
	tab[i] = 0;
	return (tab);
}
