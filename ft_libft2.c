/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_libft2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguer <kmarguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:52:37 by kmarguer          #+#    #+#             */
/*   Updated: 2022/01/15 04:20:43 by kmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	pointer_len(unsigned long long int pointer)
{
	int	ptr_len;

	ptr_len = 0;
	while (pointer != 0)
	{
		pointer /= 16;
		ptr_len++;
	}
	return (ptr_len);
}

void	ft_ptr_recurs140iq(unsigned long long ptr)
{
	if (ptr > 15)
	{
		ft_ptr_recurs140iq(ptr / 16);
		ft_ptr_recurs140iq(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'a');
	}
}

void	ft_ptr_recurs140iqcap(unsigned long long ptr)
{
	if (ptr > 15)
	{
		ft_ptr_recurs140iqcap(ptr / 16);
		ft_ptr_recurs140iqcap(ptr % 16);
	}
	else
	{
		if (ptr < 10)
			ft_putchar(ptr + '0');
		else
			ft_putchar(ptr - 10 + 'A');
	}
}

int	ft_putpointer(unsigned long long pointer)
{
	int	length;

	length = 0 + write(1, "0x", 2);
	if (pointer == 0)
		length += write(1, "0", 1);
	else
	{
		ft_ptr_recurs140iq(pointer);
		length += pointer_len(pointer);
	}
	return (length);
}

int	ft_puthex(unsigned long long pointer, char c)
{
	int	length;

	length = 0;
	if (pointer == 0)
		length += write(1, "0", 1);
	else
	{
		if (c == 'x')
			ft_ptr_recurs140iq(pointer);
		if (c == 'X')
			ft_ptr_recurs140iqcap(pointer);
		length += pointer_len(pointer);
	}
	return (length);
}
