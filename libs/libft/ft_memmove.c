/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 08:08:02 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:27 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The memmove() function copies n bytes from memory area src to memory area 
 dest. The memory areas may overlap: copying takes place as though 
 the bytes in src are first copied into a temporary array that does not 
 overlap src or dest, and the bytes are then copied from the 
 temporary array to dest. */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src > dest)
	{
		while (i < n)
		{
			*((char *)dest + i) = *((char *)src + i);
			i++;
		}
	}
	else if (dest > src)
	{
		while (n > i)
		{
			n--;
			*((char *)dest + n) = *((char *)src + n);
		}
	}
	return (dest);
}
