/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 12:11:10 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:09 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isdigit() function shall test whether c is a
       character of type digit. */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
