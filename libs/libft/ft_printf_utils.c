/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_all.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 08:33:51 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:15:19 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_args_printf(const char *format)
{
	int		i;
	int		count;
	int		len;
	char	*ptr;

	i = 0;
	count = 0;
	len = ft_strlen((char *)format);
	while (i < len)
	{
		if (format[i] == '%')
		{
			i++;
			ptr = ft_strchr("cspdiuxX%", format[i]);
			if (ptr)
				count++;
		}
		ptr = NULL;
		i++;
	}
	return (count);
}

int	ft_printf_strlen(char *str)
{
	int	len;

	len = 6;
	if (str)
		len = ft_strlen(str);
	return (len);
}
