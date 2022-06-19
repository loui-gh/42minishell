/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:01:43 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:11:56 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strdup() function returns a pointer to a new string (or NULL if 
 insufficient memory was available) which is a duplicate of the string 
 src. */

#include "libft.h"

char	*ft_strdup(char *src)
{
	int		bytes;
	char	*dest;
	int		i;

	i = 0;
	bytes = 0;
	bytes = ft_strlen(src);
	dest = (char *)malloc(sizeof(char) * bytes + 1);
	if (!dest)
		return (NULL);
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
