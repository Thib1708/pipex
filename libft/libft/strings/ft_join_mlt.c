/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_mlt.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:53:44 by tgiraudo          #+#    #+#             */
/*   Updated: 2023/02/15 13:52:47 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_join(char **all_strs)
{
	char	*new_str;
	int		i;
	int		len;

	i = -1;
	len = 0;
	while (all_strs[++i])
		len += ft_strlen(all_strs[i]);
	new_str = malloc(sizeof(char) * (len + 1));
	if (!new_str)
		return (NULL);
	new_str[0] = '\0';
	len = 0;
	i = 0;
	while (all_strs[i])
	{
		len += ft_strlen(all_strs[i]);
		ft_strlcat(new_str, all_strs[i++], len + 1);
	}
	return (new_str);
}

char	*ft_join_mlt(int nb_join, ...)
{
	va_list	strs;
	char	**all_strs;
	char	*new_str;
	int		i;

	i = -1;
	va_start(strs, nb_join);
	all_strs = malloc(sizeof(char *) * (nb_join + 1));
	if (!all_strs)
		return (NULL);
	while (++i < nb_join)
		all_strs[i] = va_arg(strs, char *);
	all_strs[i] = NULL;
	new_str = ft_join(all_strs);
	va_end(strs);
	return (free(all_strs), new_str);
}
