/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:05:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/07 21:06:37 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_fd.h"

int	ft_printf_fd(int fdd, const char *s, ...)
{
	va_list	args;
	int		i;
	int		n;

	i = 0;
	n = 0;
	va_start(args, s);
	while (s[i])
	{
		if (s[i] == '%' && s[i + 1])
		{
			i++;
			n += ft_print_type_fdd(args, s[i], fdd);
		}
		else
			n += ft_putchar_fdd(s[i], fdd);
		i++;
	}
	va_end(args);
	return (n);
}

int	ft_print_type_fdd(va_list args, char c, int fdd)
{
	if (c == 'c')
		return (ft_putchar_fdd(va_arg(args, int), fdd));
	if (c == 's')
		return (ft_putstr_fdd(va_arg(args, char *), fdd));
	if (c == 'p')
		return (print_adress_fdd(va_arg(args, void *), fdd));
	if (c == 'd' || c == 'i')
		return (ft_putnbr_fdd(va_arg(args, int), fdd));
	if (c == 'u')
		return (ft_putnbr_undec_fdd(va_arg(args, unsigned int), fdd));
	if (c == 'x')
		return (ft_putnbr_base_fdd(va_arg(args, int), "0123456789abcdef", fdd));
	if (c == 'X')
		return (ft_putnbr_base_fdd(va_arg(args, int), "0123456789ABCDEF", fdd));
	if (c == '%')
		return (ft_putchar_fdd('%', fdd));
	ft_putchar_fdd(c, fdd);
	return (1);
}
