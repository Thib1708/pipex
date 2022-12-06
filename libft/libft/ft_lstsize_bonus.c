/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 21:01:55 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/11/15 18:16:23 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *list)
{
	int	i;

	i = 0;
	if (!list)
		return (0);
	while (list)
	{
		list = list->next;
		i++;
	}
	return (i);
}
