/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:10:30 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:03 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isalpha() function shall test if c is a
       character of class alpha */

int	ft_isalpha(int c)
{
	if (!(c >= 'A' && c <= 'Z') && !(c >= 'a' && c <= 'z'))
		return (0);
	return (1);
}
