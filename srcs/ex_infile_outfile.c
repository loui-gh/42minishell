/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_infile_outfile.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/28 19:22:28 by loflavel          #+#    #+#             */
/*   Updated: 2022/06/12 10:13:24 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * function to check if we have pipes and/or infiles
 * and returns the correct FD for the input of the command
 * @param cmd [t_list *] command struct
 * @param fd_in [int] current fd for the input
 * @param child [int] child number
 * @param fd [int **] fds for pipes
 */
int	ex_infile(t_list *cmd, int fd_in, int child, int **fd)
{
	t_files	*tmp;

	if (child > 0)
	{
		fd_in = fd[child - 1][READ];
		close(fd[child - 1][WRITE]);
	}
	tmp = (ex_get_cmd_child(cmd, child))->infile;
	while (tmp)
	{
		if (fd_in != STDIN)
			close(fd_in);
		if (tmp->content[1] == ' ')
			fd_in = open(&(tmp->content[2]), O_RDONLY);
		else
			fd_in = bi_heredoc(&(tmp->content[2]), 0, "> ");
		if (fd_in < 0)
		{
			error_handler(e_file);
			exit(1);
		}
		tmp = tmp->next;
	}
	return (fd_in);
}

/**
 * function to check if we have pipes and/or outfiles
 * and returns the correct FD for the output of the command
 * @param cmd [t_list *] command struct
 * @param fd_in [int] current fd for the input
 * @param child [int] child number
 * @param fd [int **] fds for pipes
 */
int	ex_outfile(t_list *cmd, int fd_out, int child, int **fd)
{
	t_files	*tp;

	if (child != ft_lstsize(cmd) - 1)
	{
		fd_out = fd[child][WRITE];
		close(fd[child][READ]);
	}
	tp = (ex_get_cmd_child(cmd, child))->outfile;
	while (tp)
	{
		if (fd_out != STDOUT)
			close(fd_out);
		if (tp->content[1] == ' ')
			fd_out = open(&(tp->content[2]), O_CREAT | O_RDWR | O_TRUNC, 0664);
		else
			fd_out = open(&(tp->content[2]), O_CREAT | O_RDWR | O_APPEND, 0664);
		if (fd_out < 0)
		{
			error_handler(e_file);
			exit(1);
		}
		tp = tp->next;
	}
	return (fd_out);
}
