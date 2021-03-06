/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dkarhan <dkarhan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/25 12:53:13 by dkarhan           #+#    #+#             */
/*   Updated: 2022/02/25 18:25:03 by dkarhan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

int		ft_printf(const char *str, ...);
int		ft_printfchar(int c);
int		ft_printfstr(char *str);
int		ft_printfnbr(long n);
int		ft_printfchar_hex(unsigned long x, char format);
int		ft_printf_unsigned_char(unsigned int u);
int		ft_printf_ptr(unsigned long p);

#endif
