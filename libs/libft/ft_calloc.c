/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 18:20:18 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:09:57 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The calloc() function allocates memory for an array of elem elements 
 of elsize bytes each and returns a pointer to the allocated memory. 
 The memory is set to zero. */

#include "libft.h"

void	*ft_calloc(size_t elem, size_t elsize)
{
	void	*pointer;

	if (elem > 0 && (__SIZE_MAX__ / elem) < elsize)
		return (NULL);
	pointer = malloc(elem * elsize);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, elem * elsize);
	return (pointer);
}
