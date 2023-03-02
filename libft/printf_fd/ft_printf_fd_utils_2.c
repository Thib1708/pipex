/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_fd_utils_2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:01:31 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/14 16:25:09 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf_fd.h"

int	ft_putnbr_undec_fdd(unsigned int n, int fdd)
{
	if (n <= 9)
		return (ft_putchar_fdd(n + '0', fdd));
	return (ft_putnbr_fdd(n / 10, fdd) + ft_putchar_fdd((n % 10) + '0', fdd));
}

size_t	ft_strlen_fd(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
