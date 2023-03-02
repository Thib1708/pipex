/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 15:04:51 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/10 18:43:18 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_bzero(void *b, size_t n)
{
	char			*str;
	unsigned int	i;

	str = b;
	i = 0;
	while (n > i)
	{
		str[i] = '\0';
		i++;
	}
}
