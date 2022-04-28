/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:56:43 by dkarhan           #+#    #+#             */
/*   Updated: 2022/02/25 18:21:49 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_formats(va_list args, const char format)
{
	int	sum;

	sum = 0;
	if (format == 'c')
		sum += ft_printchar(va_arg(args, int));
	else if (format == 's')
		sum += ft_printstr(va_arg(args, char *));
	else if (format == 'p')
		sum += ft_print_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		sum += ft_printnbr(va_arg(args, int));
	else if (format == 'u')
		sum += ft_print_unsigned_char(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		sum += ft_printchar_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		sum += ft_printchar('%');
	return (sum);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		sum;
	va_list	args;

	i = 0;
	sum = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
			sum += ft_formats(args, str[++i]);
		else
			sum += ft_printchar(str[i]);
		i++;
	}
	va_end(args);
	return (sum);
}
