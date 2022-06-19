/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_cash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/24 14:10:22 by loflavel          #+#    #+#             */
/*   Updated: 2022/06/10 15:30:31 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

char	*pa_get_change(char *tmp, char *result, int i, int start)
{
	char	*sub;

	sub = NULL;
	sub = ft_substr(&tmp[start], 0, i - start);
	result = ft_join(result, sub);
	free(sub);
	return (result);
}

/**
 * expands the $ to env vars
 * @param tmp [char *] string with $ at position i
 * @param result [char *] string where $ is expanded to env vars 
 * @param i [int *] adress of position of $
 * @param envp [char **] array with all the env vars
 */
char	*pa_get_cash(char *tmp, char *result, int *i, char **envp)
{
	int		len;
	char	*envvar;
	char	*envtmp;

	len = 0;
	envvar = NULL;
	envtmp = NULL;
	if (!ft_strchr(&tmp[*i], '$'))
		len = ft_strlen(&tmp[*i]);
	else if (tmp[*i + 1] == '?')
		return (pa_get_cash_qmark(i, result));
	else if (ft_is_whitespace(tmp[*i + 1]) == 1 || \
				ft_ignore_char(tmp[*i + 1]) == 1)
		return (ft_join(result, "$"));
	else
		len = ft_strlen_names(&tmp[*i + 1]);
	envtmp = ft_substr(&tmp[*i], 1, len);
	envvar = ft_getenv(envtmp, envp);
	free(envtmp);
	if (envvar)
		result = ft_join(result, envvar);
	*i += len;
	return (result);
}
// char	*pa_get_cash(char *tmp, char *result, int *i, char **envp)
// {
// 	int		len;
// 	char	*envvar;
// 	char	*envtmp;

// 	len = 0;
// 	envvar = NULL;
// 	envtmp = NULL;
// 	if (!ft_strchr(&tmp[*i], '$'))
// 		len = ft_strlen(&tmp[*i]);
// 	else if (tmp[*i + 1] == '?')
// 	{
// 		*i = *i + 1;
// 		result = ft_join(result, ft_itoa(g_errno));
// 		return (result);
// 	}
// 	else if (ft_is_whitespace(tmp[*i + 1]) == 1 ||
// 				ft_ignore_char(tmp[*i + 1]) == 1)
// 	{
// 		result = ft_join(result, "$");
// 		return (result);
// 	}
// 	else
// 		len = ft_strlen_names(&tmp[*i + 1]);
// 	envtmp = ft_substr(&tmp[*i], 1, len);
// 	envvar = ft_getenv(envtmp, envp);
// 	free(envtmp);
// 	if (envvar)
// 		result = ft_join(result, envvar);
// 	*i += len;
// 	return (result);
// }

/**
 * gets one argument and finds the $ to expand to env vars
 * @param input [char *] untrimmed argument
 */
char	*pa_parse_cash(char *input, char **envp)
{
	char	*tmp;
	char	*result;
	int		start;
	int		i;

	i = 0;
	start = 0;
	tmp = ft_strtrim(input, " ");
	result = NULL;
	if (!ft_strchr(tmp, '$'))
		return (tmp);
	i = pa_parse_cash_while(&result, tmp, &start, envp);
	if (tmp[i])
	{
		result = pa_get_change(tmp, result, i, start);
	}
	free(tmp);
	return (result);
}
// char	*pa_parse_cash(char *input, char **envp)
// {
// 	int		i;
// 	char	*tmp;
// 	char	*result;
// 	int		dquotes;
// 	int		start;

// 	i = 0;
// 	dquotes = 0;
// 	start = 0;
// 	tmp = ft_strtrim(input, " ");
// 	result = NULL;
// 	if (!ft_strchr(tmp, '$'))
// 		return (tmp);
// 	while (tmp[i])
// 	{
// 		if (!dquotes && tmp[i] == '\'')
// 			i = i + pa_skip_quotes(&tmp[i]);
// 		else if (tmp[i] == '"' && !dquotes)
// 			dquotes = 1;
// 		else if (tmp[i] == '"' && dquotes)
// 			dquotes = 0;
// 		else if (tmp[i] == '$')
// 		{
// 			if (dquotes == 0 && tmp[i + 1] && tmp[i + 1] == '"')
// 				result = pa_get_change(tmp, result, (i), start);
// 			else
// 			{
// 				result = pa_get_change(tmp, result, i, start);
// 				result = pa_get_cash(tmp, result, &i, envp);
// 			}
// 			start = i + 1;
// 		}
// 		i++;
// 	}
// 	result = pa_get_change(tmp, result, i, start);
// 	return (result);
// }

char	*ft_getenv(char *str, char **envp)
{
	char	*tmp;
	int		i;
	int		size;

	i = 0;
	tmp = ft_strjoin(str, "=");
	size = ft_strlen(tmp);
	while (envp[i])
	{
		if (ft_strncmp(envp[i], tmp, size) == 0)
		{
			free(tmp);
			return (&envp[i][size]);
		}
		i++;
	}
	free(tmp);
	return (NULL);
}
