/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:09:05 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char
	*ft_strjoin(char const *s1, char const *s2)
{
	char			*ptr;
	size_t			len1;
	size_t			len2;
	unsigned long	i;

	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	ptr = (char *) malloc(sizeof(char) * (1 + len1 + len2));
	if (!ptr)
		return (0);
	i = 0;
	while (i < len1)
	{
		ptr[i] = s1[i];
		i++;
	}
	while (i < (len1 + len2))
	{
		ptr[i] = s2[i - len1];
		i++;
	}
	ptr[i] = 0;
	return (ptr);
}
