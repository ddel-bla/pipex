/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:04:10 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int
	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	char	*m1;
	char	*m2;
	size_t	i;

	m1 = (char *)s1;
	m2 = (char *)s2;
	i = 0;
	while (i < n)
	{
		if (m1[i] != m2[i])
			return (((unsigned char *)m1)[i] - ((unsigned char *)m2)[i]);
		i++;
	}
	return (0);
}
