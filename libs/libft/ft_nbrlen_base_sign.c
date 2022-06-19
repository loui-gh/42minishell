/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base_sign.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/01 13:25:39 by anruland          #+#    #+#             */
/*   Updated: 2022/05/01 13:26:35 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_nbrlen_base_sign(long long nbr, int sign, int base)
{
	size_t	len;

	len = 0;
	if (sign)
	{
		if (nbr < 0)
		{
			len++;
			nbr = -nbr;
		}
	}
	if (nbr == 0)
		len++;
	while (nbr > 0)
	{
		nbr /= base;
		len++;
	}
	return (len);
}
