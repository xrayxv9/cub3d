/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpendilh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/17 12:31:18 by mpendilh          #+#    #+#             */
/*   Updated: 2024/10/17 17:19:19 by mpendilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*cpy;
	t_list	*res;

	if (!lst || !f || !del)
		return (NULL);
	cpy = ft_lstnew(f(lst->content));
	res = cpy;
	lst = lst->next;
	while (lst)
	{
		cpy->next = ft_lstnew(f(lst->content));
		if (!cpy->next)
		{
			ft_lstclear(&res, del);
			return (NULL);
		}
		lst = lst->next;
		cpy = cpy->next;
	}
	return (res);
}
