/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thibaultgiraudon <thibaultgiraudon@stud    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:32:22 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/10 18:45:49 by thibaultgir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*str;
	unsigned int	len_s;
	size_t			new_length;
	size_t			i;

	i = 0;
	new_length = 0;
	if (!s)
		return (NULL);
	len_s = ft_strlen(s);
	if (start < len_s)
		new_length = len_s - start;
	if (new_length > len)
		new_length = len;
	str = malloc(sizeof(char) * (new_length + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && new_length > i)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
