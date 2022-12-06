/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/07 13:55:44 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/10 18:44:58 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	ch;
	int				i;
	int				len;

	i = 0;
	len = 0;
	ch = c;
	while (s[len])
		len++;
	while (i <= len)
	{
		if (s[i] == ch)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
