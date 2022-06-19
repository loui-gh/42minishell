/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_pipes.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:20:25 by anruland          #+#    #+#             */
/*   Updated: 2022/06/08 13:27:21 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * parses the command input into a list
 * 
 * @param cmd [t_list **] Pointer to the command list
 * @param input [char *] Input string
 */
int	pa_get_pipe(t_list **cmd, char *input, char ***envp)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (input[i])
	{
		if (input[i] == '|')
			break ;
		else if (input[i] == '"' || input[i] == '\'')
			i += pa_skip_quotes(&input[i]);
		i++;
	}
	tmp = ft_substr(input, 0, i);
	ft_lstadd_back(cmd, ft_lstnew(tmp));
	init_cmd(ft_lstlast(*cmd), envp);
	return (i);
}
