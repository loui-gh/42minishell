/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_pipe_red.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:09:53 by anruland          #+#    #+#             */
/*   Updated: 2022/05/27 09:48:41 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * Checks for pipes without commands in between
 * @param str [char *] string to check
 */
int	error_count_pipe(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i += pa_skip_quotes(&str[i]);
		else if (str[i] == '|' && count == 0)
			count = 1;
		else if (count == 1 && str[i] == '|')
		{
			error_handler(e_pipe);
			return (1);
		}
		else if (count == 1 && !(str[i] == '|') && !(str[i] == ' '))
			return (0);
		i++;
	}
	return (0);
}

/**
 * Checks for errors with redirections in the given string
 * subfunction
 * @param str [char *] string to check
 * @param c [char] redirection to check
 * @param count [int] counting var for the amount of redirections
 * 						if > 0 errors occurred
 */
int	error_count_c(char *str, char c, int count)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
			i += pa_skip_quotes(&str[i]);
		else if (str[i] == c && count == 0)
		{
			count = 1;
			if (str[i + 1] == c)
			{
				count = 2;
				i++;
			}
		}
		else if (count >= 1 && (str[i] == '<' || str[i] == '>'))
			return (1);
		else if (count >= 1 && !(str[i] == '<' || str[i] == '>')
			&& !(str[i] == ' '))
			count = 0;
		i++;
	}
	return (count);
}

/**
 * Checks for errors in redirections in the given list
 * @param cmd [t_list *] command struct
 */
int	error_check_redirect(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		if (error_check(tmp->content))
			return (e_redirect);
		if (error_count_c(tmp->content, '<', 0)
			|| error_count_c(tmp->content, '>', 0))
		{
			error_handler(e_redirect);
			return (e_redirect);
		}
		tmp = tmp->next;
	}
	return (e_success);
}

/**
 * Checks str for lonely pipes (start/end) and redirects (at the end)
 * @param str [char *] string to check
 */
int	error_check(char *str)
{
	int	len;
	int	error;

	error = 0;
	len = ft_strlen(str);
	if (str[len - 1] == '|' || str[0] == '|')
		error = error_handler(e_pipe);
	else if (str[len - 1] == '<' || str[len - 1] == '>')
		error = error_handler(e_redirect);
	return (error);
}
