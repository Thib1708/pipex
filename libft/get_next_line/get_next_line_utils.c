/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 12:44:31 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/24 13:21:51 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"get_next_line.h"

int	new_line(const char *s)
{
	int	i;
	int	len;

	i = 0;
	len = 0;
	if (!s)
		return (0);
	while (s[len])
		len++;
	while (i <= len)
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
