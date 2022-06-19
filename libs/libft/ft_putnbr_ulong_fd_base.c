/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_all.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 07:47:54 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:15:34 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prep_putnbr_base(char *number_array, unsigned long num, int base, int up)
{
	int	counter;

	counter = 0;
	while (num != 0)
	{
		if ((num % base) >= 10)
		{
			if (up == 1)
				number_array[counter] = (num % base) - 10 + 'A';
			else
				number_array[counter] = (num % base) - 10 + 'a';
		}
		else
			number_array[counter] = (num % base) + '0';
		num = num / base;
		counter++;
	}
	return (counter - 1);
}

void	ft_putnbr_ulong_fd_base(unsigned long nb, int fd, int base, int up)
{
	char			output[20];
	int				counter;
	unsigned long	num;

	num = nb;
	counter = 0;
	if (nb == 0)
	{
		ft_putchar_fd('0', fd);
		return ;
	}
	counter = ft_prep_putnbr_base(output, num, base, up);
	while (counter >= 0)
	{
		ft_putchar_fd(output[counter], fd);
		counter--;
	}
}
