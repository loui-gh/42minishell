/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:47:37 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:47:46 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * close unused pipes
 * @param cmd [t_list *] command struct
 * @param fd [int **] fds for pipes
 * @param child [int] number of the child
 */
void	ex_fuckoff_pipes(t_list *cmd, int **fd, int child)
{
	int	size;
	int	i;

	i = 0;
	size = ft_lstsize(cmd) - 1;
	while (i < size)
	{
		if (i != child && (i == 0 || i != child - 1))
		{
			if (fd[i][0])
				close(fd[i][0]);
			if (fd[i][1])
				close(fd[i][1]);
		}
		i++;
	}
}

/**
 * preparation of the pipes and possible in-/outfiles
 * and then calling the execute function
 * @param cmd [t_list *] command struct
 * @param fd [int **] fds for the pipes
 * @param child [int] number of the child 
 * child / child - 1	> 0 && < n
 * child 				= 0
 * child - 1 			= n
 */
void	ex_child(t_list *cmd, int **fd, int child, pid_t *cradle)
{
	int	fd_in;
	int	fd_out;

	fd_in = STDIN;
	fd_out = STDOUT;
	fd_in = ex_infile(cmd, fd_in, child, fd);
	if (fd_in != STDIN && (ex_get_cmd_child(cmd, child))->argc > 0)
	{
		dup2(fd_in, STDIN);
		close(fd_in);
	}
	fd_out = ex_outfile(cmd, fd_out, child, fd);
	if (fd_out != STDOUT && (ex_get_cmd_child(cmd, child))->argc > 0)
	{
		dup2(fd_out, STDOUT);
		close(fd_out);
	}
	ex_fuckoff_pipes(cmd, fd, child);
	cmd = ex_get_cmd_child(cmd, child);
	if (cmd->argc > 0)
	{
		ex_execute_cmd(cmd);
	}
	else
		destroy_child(cmd, cradle, fd);
}

/**
 * get the specific command for the current child
 * @param cmd [t_list *] command struct
 * @param child [int] number of the child
 */
t_list	*ex_get_cmd_child(t_list *cmd, int child)
{
	int	i;

	i = 0;
	while (cmd)
	{
		if (child == i)
		{
			return (cmd);
		}
		cmd = cmd->next;
		i++;
	}
	return (cmd);
}

/**
 * check if the command is an executable or one of the builtins
 * and execute
 * @param cmd [t_list *] command struct
 */
void	ex_execute_cmd(t_list *cmd)
{
	if (cmd->type == exec)
		execve(cmd->argv[0], cmd->argv, cmd->envp);
	else if (cmd->type == echo_b)
		bi_echo(cmd->argc, cmd->argv);
	else if (cmd->type == cd)
		cmd->envp = bi_cd(cmd->argc, cmd->argv, cmd->envp);
	else if (cmd->type == pwd)
		bi_pwd();
	else if (cmd->type == export)
		cmd->envp = bi_export(cmd->envp, cmd->argc, cmd->argv);
	else if (cmd->type == unset)
		cmd->envp = bi_unset(cmd->argc, cmd->argv, cmd->envp);
	else if (cmd->type == env)
		bi_env(cmd->envp);
	else if (cmd->type == exit_b)
		g_errno = bi_exit(cmd);
	else if (cmd->type == unknown)
	{
		error_handler(e_command);
		g_errno = 127;
	}
}
