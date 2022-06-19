/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 11:11:40 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:31 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The memset() function fills the first len bytes of the memory area 		
 pointed to by s with the constant byte c. 								*/

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*ptr;

	ptr = s;
	while (len--)
		*ptr++ = c;
	return (s);
}
