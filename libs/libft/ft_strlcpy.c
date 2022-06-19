/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:42:04 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:15 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strcpy() function copies the string pointed to by src,
	including the terminating null byte ('\0'), to the buffer pointed
	to by dest.  The strings may not overlap, and the destination
	string dest must be large enough to receive the copy. */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned int	i;
	size_t			src_size;

	src_size = 0;
	while (src[src_size] != '\0')
		src_size++;
	if (dest == 0 || size <= 0)
		return (src_size);
	i = 0;
	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (src_size);
}
