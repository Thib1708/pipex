/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:13:15 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 15:12:15 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t len)
{
	char			*dest;
	const char		*str;
	unsigned int	i;

	if (!dst && !src)
		return (NULL);
	str = src;
	dest = dst;
	i = 0;
	while (i < len)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
