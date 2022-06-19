/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_cash_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:43:02 by anruland          #+#    #+#             */
/*   Updated: 2022/06/10 15:20:23 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

char	*pa_get_cash_qmark(int *i, char *result)
{
	char	*nbr;

	nbr = ft_itoa(g_errno);
	result = ft_join(result, nbr);
	free(nbr);
	*i = *i + 1;
	return (result);
}

int	pa_parse_cash_while(char **result, char *tmp, int *start, char **envp)
{
	int		dquotes;
	int		i;

	i = 0;
	dquotes = 0;
	while (tmp[i])
	{
		if (!dquotes && tmp[i] == '\'')
			i = i + pa_skip_quotes(&tmp[i]);
		else if (tmp[i] == '"' && !dquotes)
			dquotes = 1;
		else if (tmp[i] == '"' && dquotes)
			dquotes = 0;
		else if (tmp[i] == '$')
		{
			*result = pa_get_change(tmp, *result, i, *start);
			if (!(dquotes == 0 && tmp[i + 1] && tmp[i + 1] == '"'))
				*result = pa_get_cash(tmp, *result, &i, envp);
			*start = i + 1;
		}
		i++;
	}
	*result = pa_get_change(tmp, *result, i, *start);
	return (i);
}
