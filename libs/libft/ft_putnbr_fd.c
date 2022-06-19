/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:56:27 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:40 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the integer 'nb' to the given file descriptor. */

#include "libft.h"

int	ft_prepare_nbr(char *number_array, unsigned int num)
{
	int	counter;

	counter = 0;
	while (num != 0)
	{
		number_array[counter] = (num % 10) + '0';
		num = num / 10;
		counter++;
	}
	return (counter - 1);
}

void	ft_putnbr_fd(int nb, int fd)
{
	char			output[11];
	int				counter;
	unsigned int	num;

	num = nb;
	counter = 0;
	if (nb == 0)
	{
		write(fd, "0", 1);
		return ;
	}
	if (nb < 0)
	{
		num = -nb;
		write(fd, "-", 1);
	}
	counter = ft_prepare_nbr(output, num);
	while (counter >= 0)
	{
		write(fd, &output[counter], 1);
		counter--;
	}
}
