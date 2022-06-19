/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:48:38 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:33 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The strnstr() function locates the first occurrence of the null-terminated 
  string needle in the string haystack, where not more than	len characters
  are searched. Characters that appear after a `\0'	character are not
  searched. */

#include "libft.h"

int	deep_search(char *haystack, char *needle, size_t pos_hs, size_t len)
{
	int	result;
	int	size_needle;

	size_needle = ft_strlen(needle);
	result = 1;
	haystack++;
	needle++;
	pos_hs++;
	while (*haystack != '\0' && *needle != '\0' && pos_hs < len)
	{
		if (*haystack == *needle)
			result++;
		else
			result = 0;
		haystack++;
		needle++;
		pos_hs++;
	}
	if (result != size_needle)
		result = 0;
	return (result);
}

char	*ft_strnstr(const char	*haystack, const char *needle, size_t len)
{
	char	*position;
	size_t	pos_hs;

	position = NULL;
	pos_hs = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while ((*haystack != '\0') && (pos_hs < len))
	{
		if (*haystack == *needle)
		{
			position = (char *)haystack;
			if (deep_search((char *)haystack, (char *)needle, pos_hs, len) > 0)
				break ;
			else
				position = NULL;
		}
		pos_hs++;
		haystack++;
	}
	return (position);
}
