/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:34:58 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:12:56 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Converts the lowercase char 'c' to uppercase */

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
			c = c - 32;
	return (c);
}
