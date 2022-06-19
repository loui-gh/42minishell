/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 09:30:50 by anruland          #+#    #+#             */
/*   Updated: 2022/06/08 13:28:07 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * Skip quotes and everything between them
 * @param input [char *] pointer to the first quote
 */
int	pa_skip_quotes(char *input)
{
	int		i;
	char	*tmp;

	i = 1;
	tmp = NULL;
	tmp = input;
	while (input[i])
	{
		if ((input[i] == '"' || input[i] == '\'')
			&& *(ft_strchr("'\"", input[i])) == *tmp)
			return (i);
		i++;
	}
	return (i);
}

/**
 * Initializes the command struct
 * @param cmd [t_list **] command struct
 */
void	init_cmd(t_list *cmd, char ***envp)
{
	cmd->argc = 0;
	cmd->type = unknown;
	cmd->argv = NULL;
	cmd->infile = NULL;
	cmd->outfile = NULL;
	cmd->envp = *envp;
	cmd->envp_triple = envp;
}

/**
 * Parses the input and finds commands,
 * redirects and arguments and saves them
 * to the command struct
 * @param input [char *] input from readline
 */
t_list	*pa_parse_input(char *input, t_list *cmd_input, char ***envp)
{
	int		i;

	i = 0;
	if (input_error(input))
		return (NULL);
	while (input[i])
	{
		i = i + pa_get_pipe(&cmd_input, &input[i], envp);
		if (input[i])
			i++;
	}
	free(input);
	if (error_check_redirect(cmd_input))
		return (NULL);
	pa_parse_redirect(cmd_input);
	pa_parse_cmd(cmd_input);
	pa_kill_quotes(cmd_input);
	g_errno = 0;
	pa_is_builtin(cmd_input);
	return (cmd_input);
}
