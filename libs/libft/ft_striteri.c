/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 17:40:48 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:01 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Applies the function f to each character of the string passed as argument.
	Each character is passed by address to f to be modified if necessary. */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
