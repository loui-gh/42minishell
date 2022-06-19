/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:31:20 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:11:43 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns an array of strings obtained by splitting 's'
	using the character 'c' as a delimiter. The array must be ended
	by a NULL pointer */

#include "libft.h"

size_t	ft_count_words(const char *str, char c)
{
	size_t	word;
	size_t	c_count;
	size_t	i;

	c_count = 0;
	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (str[i] != c && word == 0)
		{
			c_count++;
			word = 1;
		}
		else if (str[i] == c)
			word = 0;
		i++;
	}
	return (c_count);
}

size_t	ft_addr_diff(const char *s, char c)
{
	size_t	diff;
	char	*ptr;

	while (*s == c)
		s++;
	ptr = ft_strchr(s, c);
	diff = ptr - s;
	if (ptr == (NULL))
		diff = ft_strlen(s) - (ft_strlen(s) - ft_strlen(s));
	return (diff);
}

const char	*ft_moveptr(const char *s, size_t word_cnt)
{
	size_t	i;

	i = 0;
	while (i < word_cnt && *s != '\0')
	{
		s++;
		i++;
	}
	return (s);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	size_t	c_count;
	size_t	word_cnt;
	size_t	i;

	if (!s)
		return (NULL);
	i = 0;
	c_count = ft_count_words(s, c);
	split = (char **)ft_calloc((c_count + 1), sizeof(char *));
	if (!split)
		return (NULL);
	while (i < c_count)
	{
		word_cnt = ft_addr_diff(s, c) + 1;
		split[i] = (char *)ft_calloc(word_cnt, sizeof(char));
		while (*s == c)
			s++;
		ft_strlcpy(split[i], (char *)s, word_cnt);
		s = ft_moveptr(s, word_cnt);
		i++;
	}
	split[i] = 0;
	return (split);
}
