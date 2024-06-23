/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 19:56:35 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/05/29 19:56:35 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <stdio.h>
#include <limits.h>

int
	ft_parse(va_list args, char format)
{
	if (format == '%')
		return (ft_char(format));
	else if (format == 'c')
		return (ft_char(va_arg(args, int)));
	else if (format == 's')
		return (ft_str(va_arg(args, char *)));
	else if (format == 'p')
		return (write(1, "0x", 2) + ft_ptr(va_arg(args, void *)));
	else if (format == 'd' || format == 'i')
		return (ft_nbr(va_arg(args, int)));
	else if (format == 'u')
		return (ft_uns(va_arg(args, unsigned int)));
	else if (format == 'x' || format == 'X')
		return (ft_hex(va_arg(args, unsigned int), format));
	return (0);
}

int
	ft_char(char format)
{
	write(1, &format, 1);
	return (1);
}

int
	ft_printf(const char *format, ...)
{
	int			len;
	va_list		args;

	va_start(args, format);
	len = 0;
	while (*format != 0)
	{
		if (*format == '%')
			len += ft_parse(args, *(++format));
		else
			len += ft_char(*format);
		format++;
	}
	va_end(args);
	return (len);
}
