/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 09:56:58 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/16 14:50:50 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static int	len_nbr(int nb)
{
	int	i;

	i = 0;
	if (nb < 0)
	{
		nb *= -1;
		i++;
	}
	while (nb)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

static char	*ft_itoa2(int len, int n, int nb)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	len--;
	while (len >= 0)
	{
		str[len] = nb % 10 + '0';
		nb /= 10;
		len--;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

char	*ft_itoa(int n)
{
	int	nb;
	int	len;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		nb = -n;
	else
		nb = n;
	len = len_nbr(n);
	return (ft_itoa2(len, n, nb));
}
