/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguer <kmarguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:52:11 by kmarguer          #+#    #+#             */
/*   Updated: 2022/01/15 04:19:49 by kmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	hex_val(long long int num, char c)
{
	if (num > 9)
		return (num - 10 + c);
	return (num + '0');
}

int	parsing(char c, va_list args)
{
	if (c == 'c')
		return (ft_putchar((char)va_arg(args, int)));
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
		return (ft_putpointer(va_arg(args, unsigned long long)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr(va_arg(args, int)));
	if (c == 'u')
		return (ft_putnbr(va_arg(args, unsigned int)));
	if (c == 'X')
		return (ft_puthex(va_arg(args, unsigned int), c));
	if (c == 'x')
		return (ft_puthex(va_arg(args, unsigned int), c));
	if (c == '%')
	{
		write(1, "%%", 1);
		return (1);
	}
	return (0);
}

int	check(const char *format, va_list args)
{
	int	sum;

	sum = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			sum += parsing(*format, args);
		}
		else
		{
			write(1, format, 1);
			sum++;
		}
		format++;
	}
	return (sum);
}

int	ft_printf(const char *format, ...)
{
	int		sum;
	va_list	args;

	va_start(args, format);
	sum = check(format, args);
	va_end(args);
	return (sum);
}
