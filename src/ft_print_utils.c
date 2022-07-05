/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:56:45 by dkarhan           #+#    #+#             */
/*   Updated: 2022/02/25 18:42:49 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf_ptr(unsigned long p)
{
	write (1, "0x", 2);
	return (ft_printfchar_hex(p, 'x') + 2);
}

int	ft_printfstr(char *str)
{
	int	i;

	i = -1;
	if (!str)
		return (write(1, "(null)", 6));
	while (str[++i] != '\0')
		write(1, &str[i], 1);
	return (i);
}

int	ft_printfnbr(long n)
{
	static int	size;

	if (n < 0)
	{
		n *= -1;
		size += write(1, "-", 1);
	}
	if (n >= 10)
		ft_printfnbr(n / 10);
	size += write(1, &"0123456789"[n % 10], 1);
	return (size);
}

int	ft_printfchar_hex(unsigned long x, char format)
{
	static int	size;

	if (x >= 16)
		ft_printfchar_hex(x / 16, format);
	if (format == 'x')
		size += write(1, &"0123456789abcdef"[x % 16], 1);
	else
		size += write(1, &"0123456789ABCDEF"[x % 16], 1);
	return (size);
}

int	ft_printf_unsigned_char(unsigned int u)
{
	static int	i;

	if (u >= 10)
		ft_printf_unsigned_char(u / 10);
	i += write(1, &"0123456789"[u % 10], 1);
	return (i);
}
