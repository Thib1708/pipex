/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:43:02 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 10:54:09 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ss1;
	const unsigned char	*ss2;
	size_t				i;

	ss1 = s1;
	ss2 = s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n - 1 && *ss1 == *ss2)
	{
		ss1++;
		ss2++;
		i++;
	}
	return (*ss1 - *ss2);
}
