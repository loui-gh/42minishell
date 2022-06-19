/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_cmd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:43:35 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:43:49 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * Gets the next argument and trims it of spaces, 
 * saves it on the pointer and deletes it from the content
 * @param cmd [t_list **] Pointer to the command list
 * @param input [char *] Input string
 * @param count [int] index of the argument
 */
void	pa_get_cmd(t_list *cmd, char *input, int count)
{
	int		i;
	int		arg_found;
	char	*tmp;

	i = 0;
	arg_found = 0;
	tmp = NULL;
	while (input[i] && ft_is_whitespace(input[i]))
		i++;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			i += pa_skip_quotes(&input[i]);
		else if (input[i] == ' ')
			break ;
		i++;
		arg_found = 1;
	}
	if (arg_found)
	{
		tmp = ft_substr(input, 0, i);
		cmd->argv[count] = pa_parse_cash(tmp, cmd->envp);
		ft_memset(cmd->content, ' ', i);
		free(tmp);
	}
}

/**
 * Counts the number of arguments in a command (incl. command)
 * @param cmd [t_list **] Pointer to the command list
 * @param input [char *] Input string
 */
int	pa_count_cmd(t_list *cmd, char *input)
{
	int		i;
	int		arg_found;

	arg_found = 0;
	i = 0;
	while (input[i] && ft_is_whitespace(input[i]))
		i++;
	while (input[i])
	{
		if (input[i] == '"' || input[i] == '\'')
			i += pa_skip_quotes(&input[i]);
		else if (input[i] == ' ')
		{
			cmd->argc++;
			break ;
		}
		i++;
		arg_found = 1;
	}
	if (!input[i] && arg_found)
		cmd->argc++;
	return (i);
}

void	pa_check_cmd_exist(t_list *tmp)
{
	int	j;

	j = 0;
	while (j < tmp->argc)
	{
		pa_get_cmd(tmp, tmp->content, j);
		if (!(tmp->argv[j]) || ft_strlen(tmp->argv[j]) < 1)
			tmp->argc--;
		else
			j++;
	}
	tmp->argv[j] = NULL;
}

/**
 * Parses the content pointer and saves to argv
 * @param cmd [t_list *] command struct
 */
void	pa_parse_cmd(t_list *cmd)
{
	t_list	*tmp;
	int		i;

	tmp = cmd;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			i = i + pa_count_cmd(tmp, &tmp->content[i]);
			if (tmp->content[i])
				i++;
		}
		tmp->argv = (char **)malloc(sizeof(char *) * (tmp->argc + 1));
		if (!tmp->argv)
			error_handler(e_malloc);
		pa_check_cmd_exist(tmp);
		tmp = tmp->next;
	}
}
