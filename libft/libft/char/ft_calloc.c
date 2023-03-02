/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:13:56 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 15:33:39 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if (count == 0 || size == 0)
		return (malloc(0));
	if (MAX / size < count)
		return (NULL);
	str = malloc(sizeof(char) * (count * size));
	if (!str)
		return (NULL);
	ft_bzero(str, count * size);
	return (str);
}
