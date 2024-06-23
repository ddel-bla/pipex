/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 18:10:01 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/06/01 18:10:01 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int
	ft_str(char *str)
{
	size_t	i;

	if (str == NULL)
		return (ft_str("(null)"));
	i = 0;
	while (str[i])
		write(1, str + i++, 1);
	return (i);
}

int
	ft_nbr(int nbr)
{
	char		print;
	int			tot;
	long long	num;

	num = nbr;
	tot = 0;
	if (num < 0)
	{
		tot++;
		num *= -1;
		write (1, "-", 1);
	}
	if (num / 10 >= 1)
		tot += ft_nbr(num / 10);
	print = num % 10 + '0';
	write (1, &print, 1);
	return (tot + 1);
}

int
	ft_uns(unsigned int nbr)
{
	char	print;
	int		tot;

	tot = 0;
	if (nbr / 10 >= 1)
		tot += ft_nbr(nbr / 10);
	print = nbr % 10 + '0';
	write (1, &print, 1);
	return (tot + 1);
}

int	ft_ptr(void *ptr)
{
	unsigned long	ret;
	int				res;

	ret = (unsigned long)ptr;
	res = 0;
	if (ret > 15)
		res += ft_ptr((void *)(ret / 16));
	res += ft_char("0123456789abcdef"[ret % 16]);
	return (res);
}

int
	ft_hex(unsigned int hex, char c)
{
	int		i;
	char	print;

	i = 0;
	if ((hex / 16) >= 1)
		i += ft_hex(hex / 16, c);
	if ((hex % 16) >= 10)
		print = (hex % 16) + c - 33;
	else
		print = (hex % 16) + '0';
	write(1, &print, 1);
	return (i + 1);
}
