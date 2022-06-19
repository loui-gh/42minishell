/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:13:24 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:09:50 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The atoi() function converts the initial portion of the string pointed to by 
 str to int. */

#include "libft.h"

int	ft_is_whitespace(char c)
{
	char	whitespaces[6];
	int		counter;

	whitespaces[0] = ' ';
	whitespaces[1] = '\f';
	whitespaces[2] = '\r';
	whitespaces[3] = '\t';
	whitespaces[4] = '\v';
	whitespaces[5] = '\n';
	counter = 0;
	while (counter < 6)
	{
		if (c == whitespaces[counter])
			return (1);
		counter++;
	}
	return (0);
}

char	*skip_whitespaces(char *str)
{
	while (*str != '\0' && ft_is_whitespace(*str))
		str++;
	return (str);
}

int	ft_atoi(const char *str)
{
	int		is_negative;
	long	num;

	num = 0;
	is_negative = 0;
	str = skip_whitespaces((char *)str);
	if (*str == '-')
	{
		is_negative = !is_negative;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		num *= 10;
		num += *str - '0';
		str++;
	}
	if (is_negative)
		num = -num;
	return ((int)num);
}
