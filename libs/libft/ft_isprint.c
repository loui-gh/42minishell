/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 17:16:37 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:10:12 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* The isprint() function shall test if c is a
       character of class print */

int	ft_isprint(int c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}
