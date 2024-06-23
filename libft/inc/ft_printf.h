/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 07:40:57 by ddel-bla          #+#    #+#             */
/*   Updated: 2023/06/06 07:40:57 by ddel-bla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

int		ft_printf(const char *format, ...);
int		ft_parse(va_list args, char format);
int		ft_char(char format);
int		ft_str(char *str);
int		ft_ptr(void *ptr);
int		ft_nbr(int nbr);
int		ft_uns(unsigned int uns);
int		ft_hex(unsigned int hex, char c);

#endif
