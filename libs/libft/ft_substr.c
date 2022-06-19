/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 10:05:06 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:47 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a substring from the string 's'. The substring
  begins at index 'start' and is of maximum size 'len'. */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	end;

	i = 0;
	if (!s || ft_strlen(s) < start)
		return (ft_strdup(""));
	end = ft_strlen(s + start);
	if (end < len)
		len = end;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (!sub)
		return (NULL);
	while (i < len && *s)
	{
		sub[i] = ((char *)s)[start + i];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
