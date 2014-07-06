/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rduclos <rduclos@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/04/16 19:58:05 by rduclos           #+#    #+#             */
/*   Updated: 2014/04/16 20:28:07 by rduclos          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*lst2;
	t_list	*new;

	lst2 = NULL;
	while (lst != NULL)
	{
		new = ft_lstnew(lst->content, lst->content_size);
		new = f(new);
		if (lst2 == NULL)
			lst2 = new;
		else
			ft_lstadd(&lst2, new);
		lst = lst->next;
	}
	return (lst2);
}
