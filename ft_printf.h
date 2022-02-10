/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kmarguer <kmarguer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 00:52:31 by kmarguer          #+#    #+#             */
/*   Updated: 2022/01/15 04:27:34 by kmarguer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int				ft_putchar(char c);
int				ft_putstr(char *s);
int				num_len(long long int n);
long long int	max_num(long long int num);
int				ft_putnbr(long long int val);
int				ft_printf(const char *format, ...);
int				pointer_len(unsigned long long int pointer);
void			ft_ptr_recurs140iq(unsigned long long ptr);
void			ft_ptr_recurs140iqcap(unsigned long long ptr);
int				ft_putpointer(unsigned long long pointer);
int				ft_puthex(unsigned long long ptr, char c);
char			hex_val(long long int num, char c);
int				parsing(char c, va_list args);
int				check(const char *format, va_list args);

#endif
