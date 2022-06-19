/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:37:17 by anruland          #+#    #+#             */
/*   Updated: 2022/05/26 08:59:35 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Deletes and frees the given element and every successor of 
	that element, using the function 'del' and free.
	Finally, the pointer to the list must be set to NULL */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (del != NULL)
	{
		while (*lst)
		{
			del((*lst)->content);
			temp = *lst;
			*lst = temp->next;
			free(temp);
		}
		*lst = NULL;
	}
}
