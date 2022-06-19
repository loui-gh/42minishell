/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_quotes.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:33:53 by loflavel          #+#    #+#             */
/*   Updated: 2022/06/10 15:30:31 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * @brief saves str without quotes and joins it with result
 * 
 * @param result pointer to string to with str without quotes should be added
 * @param str string 
 * @param last pointer to end of string
 * @param i 
 */
void	pa_save_w_o_quotes(char **result, char *str, char *last, int i)
{
	char	*pre_result;

	pre_result = NULL;
	pre_result = ft_substr(str, (last - str), (&str[i] - last));
	*result = ft_join(*result, pre_result);
	ms_single_desctruct(pre_result);
}

/**
 * @brief deletes quotes from a string
 * 
 * @param str 
 * @return char* 
 */
char	*pa_really_kill_em_now(char *str, int i, char *tmp, int quotes)
{
	char	*result;
	char	*last;

	result = NULL;
	last = str;
	while (str[i])
	{
		if ((str[i] == '"' || str[i] == '\'') && !quotes)
		{
			tmp = &str[i];
			quotes = 1;
			pa_save_w_o_quotes(&result, str, last, i);
			last = tmp + 1;
		}
		else if (quotes && (str[i] == '"' || str[i] == '\'')
			&& *(ft_strchr("'\"", str[i])) == *(last - 1))
		{
			pa_save_w_o_quotes(&result, str, last, i);
			last = &str[i] + 1;
			quotes = 0;
		}
		i++;
	}
	pa_save_w_o_quotes(&result, str, last, i);
	return (result);
}

/**
 * @brief deletes quotes from all strings in cmd->argv
 * 
 * @param cmd t_list
 */
void	pa_kill_quotes(t_list *cmd)
{
	t_list	*tmp;
	int		i;
	char	*result;

	i = 0;
	tmp = cmd;
	while (tmp)
	{
		while (i < tmp->argc)
		{
			if (ft_strchr(tmp->argv[i], '\'') || ft_strchr(tmp->argv[i], '"'))
			{
				result = pa_really_kill_em_now(tmp->argv[i], 0, NULL, 0);
				ms_single_desctruct(tmp->argv[i]);
				tmp->argv[i] = result;
			}
			i++;
		}
		tmp = tmp->next;
		i = 0;
	}
}
