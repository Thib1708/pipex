/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:58:44 by tgiraudo          #+#    #+#             */
/*   Updated: 2022/12/02 13:55:13 by tgiraudo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*first;

	if (!lst || !f || !del)
		return (NULL);
	new_list = ft_lstnew(f(lst->content));
	first = new_list;
	lst = lst->next;
	while (lst)
	{
		new_list->next = ft_lstnew(f(lst->content));
		if (new_list->next == NULL)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		new_list = new_list->next;
		lst = lst->next;
	}
	new_list->next = NULL;
	return (first);
}
