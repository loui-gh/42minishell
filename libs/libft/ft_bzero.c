/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:10:02 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:09:53 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*  The bzero() function sets the first n bytes of the area starting at s 
  to zero (bytes containing "\0").  */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*((char *)s + i) = '\0';
		i++;
	}
}
