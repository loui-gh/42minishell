/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 12:20:00 by anruland          #+#    #+#             */
/*   Updated: 2022/03/30 16:27:01 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Takes as a parameter an element and frees the memory of the element's
	content using the function 'del' given as a parameter and
	free the element. The memory of 'next' must not be freed.  */

#include "libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		if (del)
			del(lst->content);
		free(lst);
	}
}
