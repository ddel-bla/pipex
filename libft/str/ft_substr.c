/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:08:13 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char
	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*ptr;
	unsigned long	i;

	if (!s)
		return (0);
	if (start + len > ft_strlen(s))
		len = ft_strlen(s) - start;
	if (ft_strlen(s) < start)
		len = 0;
	ptr = (char *) malloc (sizeof (char) * (len + 1));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len)
	{
		if (s[start + i])
			ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
