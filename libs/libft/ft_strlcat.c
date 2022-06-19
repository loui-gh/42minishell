/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:40:21 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:11 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* strlcat concatenates strings. It takes the full size of
 the buffer (not just the length) and guarantee to NUL-terminate
 the result (as long as there is at least one byte free in dest).
 Note that a byte for the NUL should be included in size. Also note
 that strlcat() only operates on true ''C'' strings. This means
 that for strlcat() both src and dest must be NUL-terminated.

 The strlcat() function appends the NUL-terminated string src to the 
 end of dest. It will append at most size - strlen(dest) - 1 bytes, 
 NUL-terminating the result.

 The strlcat() function returns the total length of the string it
 tried to create. For strlcat() that means the initial length of 
 dest plus the length of src. While this may seem somewhat confusing, 
 it was done to make truncation detection simple.
 Note, however, that if strlcat() traverses size characters without 
 finding a NUL, the length of the string is considered to be size 
 and the destination string will not be NUL-terminated (since there 
 was no space for the NUL). This keeps strlcat() from running off 
 the end of a string. In practice this should not happen (as it 
 means that either size is incorrect or that dest is not a proper 
 ''C'' string). The check exists to prevent potential security 
 problems in incorrect code. 
*/

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dest;

	i = 0;
	j = 0;
	while (dest[i] != '\0' && i < size)
		i++;
	len_dest = i;
	if (size == 0)
		return (ft_strlen((char *)src));
	if (size == len_dest)
		return (size + ft_strlen((char *)src));
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (len_dest + ft_strlen((char *)src));
}
