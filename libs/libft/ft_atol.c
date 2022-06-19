/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/24 14:00:39 by anruland          #+#    #+#             */
/*   Updated: 2022/05/06 20:26:24 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_whitespace(char c);

char	*skip_whitespaces(char *str);

long	ft_atol(const char *str)
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
	return (num);
}
