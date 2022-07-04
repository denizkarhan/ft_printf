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

#include "../include/ft_printf.h"

int	ft_printfchar(int c)
{
	return (write(1, &c, 1));
}

int	ft_formats(va_list args, const char format)
{
	int	sum;

	sum = 0;
	if (format == 'c')
		sum += ft_printfchar(va_arg(args, int));
	else if (format == 's')
		sum += ft_printfstr(va_arg(args, char *));
	else if (format == 'p')
		sum += ft_printf_ptr(va_arg(args, unsigned long long));
	else if (format == 'd' || format == 'i')
		sum += ft_printfnbr(va_arg(args, int));
	else if (format == 'u')
		sum += ft_printf_unsigned_char(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		sum += ft_printfchar_hex(va_arg(args, unsigned int), format);
	else if (format == '%')
		sum += write(1, "%%", 1);
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
			sum += write(1, &str[i], 1);
		i++;
	}
	va_end(args);
	return (sum);
}
