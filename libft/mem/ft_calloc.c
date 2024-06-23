/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:06:09 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>

void
	*ft_calloc(size_t count, size_t size)
{
	void	*ptr;
	size_t	len;

	if (count == ULONG_MAX || size == ULONG_MAX)
		return (0);
	len = count * size;
	ptr = (char *)malloc(len);
	if (!ptr)
		return (0);
	return (ft_bzero(ptr, len));
}
