/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 19:20:38 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:37 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Outputs the string 'str' to the given file descriptor followed by
	a newline. */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
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
	write(fd, "\n", 1);
}
