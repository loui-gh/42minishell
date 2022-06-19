/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:40:56 by anruland          #+#    #+#             */
/*   Updated: 2022/05/22 12:26:29 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates (with malloc) and returns a new element. The variable 'content'
	is initialized with the value of the parameter 'content'.
	The variable 'next' is initialized to NULL */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*list;

	list = malloc(sizeof(t_list));
	if (list == NULL)
		return (NULL);
	if (content == NULL)
		list->content = 0;
	else
		list->content = content;
	list->next = 0;
	return (list);
}

t_files	*ft_filenew(void *content)
{
	t_files	*list;

	list = malloc(sizeof(t_files));
	if (list == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}
