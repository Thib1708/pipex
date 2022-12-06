/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils_2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 09:01:31 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/24 13:20:31 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

int	ft_putnbr_undec(unsigned int n)
{
	if (n >= 0 && n <= 9)
		return (ft_putchar(n + '0'));
	return (ft_putnbr(n / 10) + ft_putchar((n % 10) + '0'));
}

