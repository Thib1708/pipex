/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 20:27:27 by thibaultgir       #+#    #+#             */
/*   Updated: 2022/12/02 13:54:16 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*e;

	e = malloc(sizeof(*e));
	if (!e)
		return (NULL);
	e->content = content;
	e->next = NULL;
	return (e);
}
