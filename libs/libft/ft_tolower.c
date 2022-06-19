/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:39:54 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:52 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts the uppercase char 'c' to lowercase */

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
			c = c + 32;
	return (c);
}
