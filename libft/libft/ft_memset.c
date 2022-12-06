/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 14:03:57 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/10 18:44:17 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	char			*str;
	unsigned int	i;

	str = b;
	i = 0;
	while (len > i)
	{
		str[i] = c;
		i++;
	}
	return (str);
}
