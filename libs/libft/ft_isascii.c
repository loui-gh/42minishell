/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:17:28 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:06 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isascii() function shall test whether c is a 7-bit US-ASCII
       character code. */

int	ft_isascii(int c)
{
	if (c >= 0 && c <= 127)
		return (1);
	return (0);
}
