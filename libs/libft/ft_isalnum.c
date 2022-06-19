/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:16:37 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:00 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isalnum() function shall test whether c is a
       character of class alpha or digit */

#include "libft.h"

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}
