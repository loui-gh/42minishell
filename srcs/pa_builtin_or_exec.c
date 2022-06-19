/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pa_builtin_or_exec.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:47:50 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:47:58 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * checks to see if cmd is a builtin and
 * sets type to exact builtin
 * IDEA purpose of this is to have ft_execute(t_list *cmd, int type) 
 * if command not builtin or exec, cmd->type remains 'unknown'
 */
void	pa_is_builtin(t_list *cmd)
{
	int	len;

	while (cmd)
	{
		if (cmd->argc < 1)
			break ;
		len = ft_strlen(cmd->argv[0]) + 1;
		if (ft_strncmp("echo", cmd->argv[0], len) == 0)
			cmd->type = echo_b;
		else if (ft_strncmp("cd", cmd->argv[0], len) == 0)
			cmd->type = cd;
		else if (ft_strncmp("pwd", cmd->argv[0], len) == 0)
			cmd->type = pwd;
		else if (ft_strncmp("export", cmd->argv[0], len) == 0)
			cmd->type = export;
		else if (ft_strncmp("unset", cmd->argv[0], len) == 0)
			cmd->type = unset;
		else if (ft_strncmp("env", cmd->argv[0], len) == 0)
			cmd->type = env;
		else if (ft_strncmp("exit", cmd->argv[0], len) == 0)
			cmd->type = exit_b;
		else
			pa_is_exec(cmd);
		cmd = cmd->next;
	}
}

char	*ft_strjoin_mod(char const *s1, char const *s2, size_t lazy, char x)
{
	size_t	j;
	char	*newstring;

	j = 0;
	newstring = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 2));
	if (!newstring)
		return (NULL);
	while (s1[lazy] != '\0')
	{
		newstring[j] = s1[lazy];
		lazy++;
		j++;
	}
	newstring[j] = x;
	j++;
	lazy = 0;
	while (s2[lazy] != '\0')
	{
		newstring[j] = s2[lazy];
		j++;
		lazy++;
	}
	newstring[j] = '\0';
	return (newstring);
}

static void	join_cmd_path(t_list *cmd, char **path)
{
	int		i;
	size_t	j;
	char	*exec_cmd;

	i = 0;
	while (path[i])
	{
		j = 0;
		exec_cmd = ft_strjoin_mod(path[i], cmd->argv[0], j, '/');
		if (access(exec_cmd, X_OK) == 0)
		{
			cmd->type = exec;
			free (cmd->argv[0]);
			cmd->argv[0] = exec_cmd;
			break ;
		}
		else
			free(exec_cmd);
		i++;
	}
	ms_free_array(path);
}

void	join_relative_path(t_list *cmd)
{
	char	**pwd;

	pwd = (char **)malloc(sizeof(char *) * 2);
	*pwd = (char *)malloc(sizeof(char) * PATH_SIZE);
	pwd[1] = 0;
	getcwd(*pwd, PATH_SIZE);
	if (cmd->argv[0][1] == '.')
		join_cmd_path(cmd, pwd);
	else
	{
		ft_memcpy(cmd->argv[0], &(cmd->argv[0][1]), ft_strlen(cmd->argv[0]));
		join_cmd_path(cmd, pwd);
	}
}

void	pa_is_exec(t_list *cmd)
{
	char	**path;

	if (ft_strlen(cmd->argv[0]) < 1)
		return ;
	if (cmd->argv[0][0] == '/' && access(cmd->argv[0], X_OK) == 0)
	{
		if (closedir(opendir(cmd->argv[0])) != -1)
			error_handler(e_dir);
		else
			cmd->type = exec;
	}
	else if (cmd->argv[0][0] == '.')
		join_relative_path(cmd);
	else
	{
		path = ft_split(ft_getenv("PATH", cmd->envp), ':');
		if (path == NULL)
		{
			return ;
		}
		else
			join_cmd_path(cmd, path);
	}
}
