/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:57:04 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:44 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string 'str' to the given file descriptor */

#include "libft.h"

void	ft_putstr_fd(char *str, int fd)
{
	int	count;

	count = 0;
	if (!str)
		return ;
	while (str[count] != '\0')
	{
		write(fd, &str[count], 1);
		count++;
	}
}
