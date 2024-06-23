/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 15:11:05 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/11/03 05:32:50 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

size_t
	ft_int_len(long i)
{
	size_t	len;

	len = 1;
	if (i < 0)
	{
		i *= -1;
		len++;
	}
	while (i > 9)
	{
		i /= 10;
		len++;
	}
	return (len);
}

char
	*ft_itoa(int n)
{
	char	*res;
	size_t	len;
	long	ln;

	ln = n;
	len = ft_int_len(ln);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len--] = 0;
	if (ln == 0)
		res[0] = '0';
	if (ln < 0)
	{
		res[0] = '-';
		ln *= -1;
	}
	while (ln > 0)
	{
		res[len] = (ln % 10) + '0';
		ln /= 10;
		len--;
	}
	return (res);
}
