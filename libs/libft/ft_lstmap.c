/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:46:10 by anruland          #+#    #+#             */
/*   Updated: 2022/03/30 16:41:44 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Iterates the list 'lst' and applies the function 'f' to the
	content of each element. Creates a new list resulting of the 
	successive applications of the function 'f'. The 'del' function 
	is used to delete the content of an element if needed. */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*temp;

	new = NULL;
	while (lst)
	{
		temp = ft_lstnew((*f)(lst->content));
		if (!temp)
		{
			while (new)
			{
				temp = new->next;
				(*del)(new->content);
				free(new);
				new = temp;
			}
			return (NULL);
		}
		ft_lstadd_back(&new, temp);
		lst = lst->next;
	}
	return (new);
}
