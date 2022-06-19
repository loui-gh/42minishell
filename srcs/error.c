/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:19:26 by loflavel          #+#    #+#             */
/*   Updated: 2022/06/10 15:30:31 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * Checks the string str for unclosed quotes
 * 39 = ' - 34 = "
 * if one type of quote is found the other gets ignored
 * until the quotes are closed
 * @param str [char *] string to check
 */
int	input_error(char *str)
{
	int	dq;
	int	sq;
	int	i;

	dq = 0;
	sq = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' && dq % 2 == 0)
			sq++;
		else if (str[i] == '"' && sq % 2 == 0)
			dq++;
		i++;
	}
	if (sq % 2 == 1 || dq % 2 == 1)
	{
		error_handler(e_quotes);
		return (e_quotes);
	}
	return (0);
}

int	error_non_syntax(int error)
{
	g_errno = 1;
	if (error == e_malloc)
		ft_putstr_fd("Error: malloc of argv failed\n", 2);
	else if (error == e_child_died)
		ft_putstr_fd("Error: complications during birth\n", 2);
	else if (error == e_file)
		ft_putstr_fd("Error: no R/W permissions OR file/dir not found\n", 2);
	else if (error == e_dir)
	{
		g_errno = 127;
		ft_putstr_fd("Error: It's a directory, bro.\n", 2);
	}
	else if (error == e_command)
		ft_putstr_fd("Error: command not found\n", 2);
	else if (error == e_args)
		ft_putstr_fd("Error: Too many or wrong arguments\n", 2);
	else if (error == e_heredoc)
	{
		ft_putstr_fd("Warning: here-document delimited by end of file\n", 2);
		g_errno = 0;
	}
	else
		ft_putstr_fd("Error: unknown\n", 2);
	return (error);
}

/**
 * Prints custom error messages according to error enum input
 * errno to exit_code
 * @param error [int] custom enum error code
 */
int	error_handler(int error)
{
	g_errno = 2;
	if (error == e_pipe)
		ft_putstr_fd("Syntax Error: near unexpected token '|'\n", 2);
	else if (error == e_redirect)
		ft_putstr_fd("Syntax Error: invalid use of '<' or '>'\n", 2);
	else if (error == e_quotes)
		ft_putstr_fd("Error: unclosed quotes\n", 2);
	else
		error_non_syntax(error);
	return (error);
}

/**
 * Checks if the string is empty or contains only spaces
 * Returns -1 on empty string
 * @param str [char *] the string to check
 */
int	input_empty(char *str)
{
	char	*tmp;

	if (!str[0])
		return (-1);
	tmp = ft_strtrim(str, " ");
	if (str && ft_strlen(tmp) < 1)
	{
		g_errno = 127;
		free(tmp);
		return (-1);
	}
	free(tmp);
	return (0);
}
