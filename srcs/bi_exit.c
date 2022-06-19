/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:43:12 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:43:27 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * @brief checks if str is numeric
 * 
 * @param str string
 * @return int, 1 if str is numeric, 0 if not 
 */
int	bi_is_numeric(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief exits with error code argv[1]
 * 
 * @param argc number of arguments
 * @param argv array of arguments
 * @return int error code
 */
int	bi_exit(t_list *cmd)
{
	if (cmd->argc > 2)
		error_handler(e_args);
	else if (cmd->argc == 1)
	{
		g_errno = 0;
	}
	else
	{
		if (bi_is_numeric(cmd->argv[1]) == 0)
		{
			error_handler(e_args);
			g_errno = 2;
		}
		else
			g_errno = atoi(cmd->argv[1]);
	}
	ft_printf("exit\n");
	ms_destructor(cmd);
	exit(g_errno);
	return (g_errno);
}
