/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 13:20:44 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 18:11:44 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s)
{
	char	*str;
	char	*ptr;
	int		len;

	len = 0;
	while (s[len])
		len++;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	ptr = str;
	while (*s)
		*ptr++ = *s++;
	*ptr = '\0';
	return (str);
}
