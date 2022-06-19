/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 12:24:25 by anruland          #+#    #+#             */
/*   Updated: 2022/06/10 15:29:46 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	bi_env(char **envp)
{
	while (*envp)
	{
		if (ft_strchr(*envp, '=') != NULL)
			ft_printf("%s\n", *envp);
		envp++;
	}
}
