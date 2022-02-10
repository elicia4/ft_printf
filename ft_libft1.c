/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguer <kmarguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:52:20 by kmarguer          #+#    #+#             */
/*   Updated: 2022/01/15 04:11:41 by kmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *s)
{
	size_t	length;

	length = -1;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[++length])
		write(1, &s[length], 1);
	return (length);
}

int	num_len(long long int n)
{
	long long int	length;

	length = 0;
	if (n < 1)
		length++;
	while (n != 0)
	{
		n /= 10;
		length++;
	}
	return (length);
}

long long int	max_num(long long int num)
{
	long long int	res;

	res = 1;
	while (num)
	{
		res *= 10;
		num /= 10;
	}
	return (res / 10);
}

int	ft_putnbr(long long int val)
{
	long long int	num;
	long long int	n_len;
	int				digit;
	int				length;

	num = val;
	length = num_len(num);
	if (num < 0)
	{
		num *= -1;
		ft_putchar('-');
	}
	n_len = max_num(num);
	while (n_len > 9)
	{
		digit = (num / n_len) % 10;
		n_len /= 10;
		ft_putchar(digit + '0');
	}
	if (n_len <= 9)
		ft_putchar((num % 10) + '0');
	return (length);
}
