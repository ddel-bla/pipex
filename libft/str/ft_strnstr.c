/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 19:54:46 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char *
	ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	unsigned long	i;
	unsigned long	needlelen;

	if (ft_strlen(haystack) < len)
		len = ft_strlen(haystack);
	i = 0;
	needlelen = ft_strlen(needle);
	while (i + needlelen <= len)
	{
		if (ft_strncmp(haystack + i, needle, needlelen) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (0);
}
