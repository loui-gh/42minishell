/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printerror.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 17:32:46 by anruland          #+#    #+#             */
/*   Updated: 2022/05/05 17:35:07 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printerror(char *errormsg)
{
	ft_printf("%s\n", errormsg);
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
