/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 11:21:57 by anruland          #+#    #+#             */
/*   Updated: 2022/06/10 15:29:46 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * Save the name of the outfile(s) to the created.
 * Need to know the name of last outfile to know where to redirect input
 * @param cmd [t_list *] command struct
 * @param file [char *] new list
 * @param direction [char] chevron for direction
 */
void	pa_create_file_ll(t_list *cmd, char *file, char direction)
{
	if (direction == '>')
		ft_fileadd_back(&(cmd->outfile), ft_filenew(file));
	if (direction == '<')
		ft_fileadd_back(&(cmd->infile), ft_filenew(file));
}

/**
 * Saves the redirect to the command struct
 * @param cmd [t_list *] command struct
 * @param redirect [char *] pointer to the start of redirect
 * @param i [int] index to calc the whole redirect
 */
void	pa_save_redirect(t_list *cmd, char *redirect, int i)
{
	char	*tmp;
	char	*end;
	char	*prefix;
	char	*file;

	prefix = ft_substr(redirect, 0, 2);
	ft_memset(redirect, ' ', 1);
	if (prefix[1] != prefix[0])
		prefix[1] = ' ';
	else
		ft_memset(redirect + 1, ' ', 1);
	end = cmd->content + i;
	file = ft_substr(redirect, 0, end - redirect);
	tmp = ft_strtrim(file, " ");
	free(file);
	file = ft_strjoin(prefix, tmp);
	if (*file == '<')
		pa_create_file_ll(cmd, file, '<');
	else if (*file == '>')
		pa_create_file_ll(cmd, file, '>');
	ft_memset(redirect, ' ', end - redirect);
	free(prefix);
	free(tmp);
}

/**
 * parses the command input into a list
 * 
 * @param cmd [t_list **] Pointer to the command list
 * @param input [char *] Input string
 */
int	pa_get_redirect(t_list *cmd)
{
	int		i;
	char	*redirect;

	i = 0;
	redirect = NULL;
	while (cmd->content[i])
	{
		if ((cmd->content[i] == '>' || cmd->content[i] == '<'))
		{
			redirect = cmd->content + i++;
			if (cmd->content[i] == '>' || (cmd->content[i] == '<'))
				i++;
			while (cmd->content[i] && ft_is_whitespace(cmd->content[i]))
				i++;
			while (cmd->content[i] && !ft_is_whitespace(cmd->content[i]))
				i++;
			break ;
		}
		else if (cmd->content[i] == '"' || cmd->content[i] == '\'')
			i += pa_skip_quotes(&cmd->content[i]);
		i++;
	}
	if (redirect)
		pa_save_redirect(cmd, redirect, i);
	return (i);
}

/**
 * parses the redirects and saves to the command struct
 * @param cmd [t_list *] command struct
 */
void	pa_parse_redirect(t_list *cmd)
{
	t_list	*tmp;
	int		i;

	tmp = cmd;
	while (tmp)
	{
		i = 0;
		while (tmp->content[i])
		{
			i = pa_get_redirect(tmp);
			if (tmp->content[i])
				i++;
		}
		tmp = tmp->next;
	}
}
