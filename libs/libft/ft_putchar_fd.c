/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/09 09:56:00 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:34 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Writes the char 'c' to the given filedescriptor 'fd' */

#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
