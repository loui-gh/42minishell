/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 10:02:20 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:05 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a new string, wich is the result of the 
	concatenation of s1 and s2 */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	size_s1;
	size_t	size_s2;
	size_t	i;
	char	*concat;

	i = 0;
	if (!s1 || !s2)
		return (NULL);
	size_s1 = ft_strlen((char *)s1);
	size_s2 = ft_strlen((char *)s2);
	concat = (char *)malloc(sizeof(char) * (size_s1 + size_s2 + 1));
	if (!concat)
		return (NULL);
	while (i < (size_s1 + size_s2))
	{
		if (i < size_s1)
			concat[i] = s1[i];
		else if (i < (size_s1 + size_s2))
			concat[i] = s2[i - size_s1];
		i++;
	}
	concat[i] = '\0';
	return (concat);
}
