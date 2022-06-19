/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:45:38 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:45:45 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * @brief checks which chars to ignore or pay attn to.
 * 
 * @param c 
 * @return int: 0 = do not ignore; 1 = ignore
 */
int	ft_ignore_char(char c)
{
	char	symbols[6];
	int		counter;

	symbols[0] = ':';
	symbols[1] = '=';
	symbols[2] = '*';
	symbols[3] = '\0';
	symbols[4] = '"';
	counter = 0;
	while (counter < 5)
	{
		if (c == symbols[counter])
			return (1);
		counter++;
	}
	return (0);
}

char	*ft_strrchr_mod(const char *s, int c, int end)
{
	char	*ptr;
	int		i;

	i = 0;
	ptr = NULL;
	while (s[i] && i < end)
	{
		if (s[i] == (char)c)
			ptr = (char *)&s[i];
		i++;
	}
	if (s[i] == (char)c)
		ptr = (char *)&s[i];
	return (ptr);
}

/**
 * Checks if the given string is the name of the variable
 * @param str [char *] string to check
 */
int	ft_strlen_names(char *str)
{
	int	str_count;

	str_count = 0;
	while (ft_isalnum(str[str_count]) || str[str_count] == '_')
		str_count++;
	return (str_count);
}

/**
 * The first part of the argument will be duplicated and all
 * after that joined to the new pointer and then s1 gets properly
 * freed
 * @param s1 [char *] if string 1 exists join and free
 * @param s1 [char *] if only s2 exists strdup it
 */
char	*ft_join(char *s1, char *s2)
{
	char	*tmp;

	if (s1)
	{
		tmp = ft_strjoin(s1, s2);
		free(s1);
	}
	else if (ft_strlen(s2) > 0)
		tmp = ft_strdup(s2);
	else
		tmp = NULL;
	return (tmp);
}
