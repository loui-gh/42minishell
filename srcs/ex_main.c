/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ex_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 14:47:48 by anruland          #+#    #+#             */
/*   Updated: 2022/06/09 08:37:49 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * opens the pipes if there are more than 1 commands
 * @param fd [int **] array of file descriptors. each pipe consists of one 
 * 						fd to write to (1) and one to read from (0)
 * @param n [int] number of commands in the struct
 */
void	ex_open_pipes(int **fd, int n)
{
	int	i;

	i = 0;
	while (i < (n - 1))
	{
		if (pipe(fd[i]) < 0)
			error_handler(e_pipe);
		i++;
	}
}

void	ex_child_handling(t_list *cmd, int **fd, pid_t *cradle, int child)
{
	if (cradle[child] < 0)
	{
		error_handler(e_child_died);
		return ;
	}
	else if (cradle[child] == 0)
	{
		ex_child(cmd, fd, child, cradle);
		ms_destroy_pipes(fd, ft_lstsize(cmd));
		ms_destructor(cmd);
		exit(g_errno);
	}
}

/**
 * child fork function
 * forks the children. after the fork everything is copied. one
 * for each child and one for the parent. if the code runs on 
 * the child we can call the execution function. if it will be 
 * a builtin, we need to come back to this point and destroy 
 * destroy the unused pipe endings and all allocated memory before
 * the child exits.
 * if we are on the parent, we wait for the children to die
 * @param cradle [pid_t *] pointer to the PID information (if 0 -> child)
 * @param fd [int **] file descriptors for pipe endings
 * @param n [int] number of commands (children)
 * @param cmd [t_list *] command struct
 */
void	ex_give_birth(pid_t *cradle, int **fd, int n, t_list *cmd)
{
	int	child;
	int	status;

	child = 0;
	si_init_sighandling_child();
	while (child < n)
	{
		cradle[child] = fork();
		ex_child_handling(cmd, fd, cradle, child);
		child++;
	}
	child = 0;
	while (child < n)
	{
		if (child != (n - 1))
		{
			close(fd[child][0]);
			close(fd[child][1]);
		}
		if (waitpid(-1, &status, 0) == cradle[n - 1])
			g_errno = WEXITSTATUS(status);
		child++;
	}
	si_init_sighandling();
	ms_destroy_pipes(fd, ft_lstsize(cmd));
}

int	**ex_create_fds(int **fd, int n)
{
	int	i;

	i = 0;
	if (n > 1)
	{
		fd = (int **)malloc(sizeof(int *) * (n - 1));
		while (i < (n - 1))
		{
			fd[i] = (int *)malloc(sizeof(int) * 2);
			i++;
		}
	}
	else
		fd = NULL;
	return (fd);
}

/**
 * Executor entry point
 * mallocs file descriptors (fd) for pipes and cradle for child PIDs
 * calls child fork function (give_birth)
 * @param cmd [t_list *] command struct
 */
void	ex_execute(t_list *cmd)
{
	int		n;
	int		**fd;
	pid_t	*cradle;

	fd = NULL;
	n = ft_lstsize(cmd);
	fd = ex_create_fds(fd, n);
	ex_open_pipes(fd, n);
	if (n == 1 && (cmd->type == cd || cmd->type == unset
			|| cmd->type == export || cmd->type == exit_b))
		ex_execute_cmd(cmd);
	else
	{
		cradle = (pid_t *)malloc(sizeof(pid_t) * n);
		ex_give_birth(cradle, fd, n, cmd);
		free (cradle);
	}	
}
