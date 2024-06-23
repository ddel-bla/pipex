/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:09:41 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char
	*ft_strtrim(char const *s1, char const *set)
{
	unsigned long	end;
	unsigned long	start;
	unsigned long	srclen;

	start = 0;
	srclen = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < srclen)
		start++;
	end = 0;
	while (ft_strchr(set, s1[srclen - end]) && start < srclen - end)
		end++;
	return (ft_substr(s1, start, srclen - start - (end - 1)));
}
