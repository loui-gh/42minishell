/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:14:19 by anruland          #+#    #+#             */
/*   Updated: 2022/06/06 09:16:08 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Adds the element 'new' at the end of the list. */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (*lst == NULL)
		*lst = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
}

void	ft_fileadd_back(t_files **lst, t_files *new)
{
	t_files	*last;

	if (*lst == NULL)
	{
		*lst = new;
	}
	else
	{
		last = ft_filelast(*lst);
		last->next = new;
	}
}
