/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 19:21:18 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/09 17:51:38 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_fd.h"

int	ft_putchar_fdd(char c, int fdd)
{
	return (write(fdd, &c, 1));
}

int	ft_putnbr_fdd(long nb, int fdd)
{
	if (nb < 0)
		return (ft_putchar_fdd('-', fdd) + ft_putnbr_fdd(-nb, fdd));
	if (nb <= 9)
		return (ft_putchar_fdd(nb + '0', fdd));
	return (ft_putnbr_fdd(nb / 10, fdd) + ft_putchar_fdd(nb % 10 + '0', fdd));
}

int	ft_putstr_fdd(char *s, int fdd)
{
	int	n;

	n = 0;
	if (!s)
		return (ft_putstr_fdd("(null)", fdd));
	while (*s)
		n += ft_putchar_fdd(*s++, fdd);
	return (n);
}

int	ft_putnbr_base_fdd(long int nb, char *base, int fdd)
{
	if (nb < 0)
		return (ft_putnbr_base_fdd(4294967296 + nb, base, fdd));
	if (nb < 16)
		return (ft_putchar_fdd(base[nb % 16], fdd));
	return (ft_putnbr_base_fdd(nb / 16, base, fdd) + \
	ft_putchar_fdd(base[nb % 16], fdd));
}

int	print_adress_fdd(void *addr, int fdd)
{
	unsigned long	address;
	char			adr[17];
	char			*hexa;
	int				i;

	if (!addr)
		return (ft_putstr_fdd("0x0", fdd));
	address = (long int)addr;
	i = 0;
	hexa = "0123456789abcdef";
	while (address)
	{
		adr[i++] = hexa[address % 16];
		address /= 16;
	}
	adr[i] = '\0';
	ft_putstr_fdd("0x", fdd);
	while (--i >= 0)
		ft_putchar_fdd(adr[i], fdd);
	return (ft_strlen_fd(adr) + 2);
}
