/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 16:59:35 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:16 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Allocates and returns a string representing the integer received as 
  an argument. Negative numbers must be handled. */

#include "libft.h"

char	*ft_reverse(char *ptr)
{
	char	*rev;
	size_t	len;
	size_t	i;

	i = 0;
	len = 0;
	len = ft_strlen(ptr);
	rev = (char *)malloc(sizeof(char) * (len + 1));
	if (!rev)
		return (NULL);
	while (i < len)
	{
		rev[i] = ptr[len - i - 1];
		i++;
	}
	rev[i] = '\0';
	return (rev);
}

char	*ft_prepare_numbers(char *number_array, int n)
{
	unsigned int	num;
	int				counter;

	num = n;
	counter = 0;
	if (num == 0)
	{
		number_array[0] = '0';
		number_array[1] = '\0';
		return (ft_reverse(number_array));
	}
	if (n < 0)
		num = -n;
	while (num != 0)
	{
		number_array[counter] = (num % 10) + '0';
		num = num / 10;
		counter++;
	}
	if (n < 0)
		number_array[counter] = '-';
	number_array[counter + 1] = '\0';
	return (ft_reverse(number_array));
}

char	*ft_itoa(int n)
{
	char	output[12];
	char	*ptr;

	ft_bzero(output, 12);
	ptr = ft_prepare_numbers(output, n);
	if (!ptr)
		return (NULL);
	return (ptr);
}
