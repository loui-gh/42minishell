/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 18:41:54 by anruland          #+#    #+#             */
/*   Updated: 2022/05/06 08:41:51 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *addr, size_t size)
{
	void	*ptr;
	size_t	i;

	if (size == 0)
		return (NULL);
	ptr = malloc(size);
	if (!ptr)
	{
		if (size <= 0)
			free(addr);
		return (NULL);
	}
	i = 0;
	while (i < size && *(char *)(addr + i))
	{
		*(char *)(ptr + i) = *(char *)(addr + i);
		i++;
	}
	*(char *)(ptr + (size - 1)) = '\0';
	free(addr);
	return (ptr);
}
