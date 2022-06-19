/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:01:06 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:43 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a copy of 's1' with the characters specified 
	in 'set' removed from the beginning and the end of the string. */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trimmed;
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlen((char *)s1);
	while (ft_strchr(set, s1[i]) && s1[i] != '\0')
		i++;
	while (ft_strchr(set, s1[len - 1]) && len != 1)
		len--;
	trimmed = ft_substr(s1, (unsigned int) i, (len - i));
	return (trimmed);
}
