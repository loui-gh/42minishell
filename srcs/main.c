/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:45:24 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:45:34 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	g_errno = 0;

char	**array_cpy(char **envp)
{
	int		i;
	int		size;
	char	**envp_malloc;

	i = 0;
	envp_malloc = (char **)malloc((sizeof_array(envp) + 1) * sizeof(char *));
	size = sizeof_array(envp);
	while (i < size)
	{
		envp_malloc[i] = ft_substr(envp[i], 0, ft_strlen(envp[i]));
		i++;
	}
	envp_malloc[i] = NULL;
	return (envp_malloc);
}

void	ms_check_input(char *input, char ***envp_ptr, t_list *cmd)
{
	if (input)
	{
		if (input_empty(input) == 0 && !error_check(input) \
				&& !error_count_pipe(input))
			cmd = pa_parse_input(input, cmd, envp_ptr);
		if (g_errno == 0)
		{
			ex_execute(cmd);
			*envp_ptr = cmd->envp;
			ms_destructor(cmd);
		}
	}
}

void	ms_exit_ctrld(char ***envp_ptr)
{
	ft_printf("exit\n");
	ms_free_array(*envp_ptr);
	free(envp_ptr);
	rl_clear_history();
	exit(0);
}

/**
 * destroys one single pointer
 * @param str [void *] pointer to free
 */
char	*ms_input_desctruct(void *str)
{
	if (str)
		free(str);
	str = NULL;
	return (str);
}

int	main(int argc, char **argv, char **envp)
{
	char		*input;
	char		***envp_ptr;
	t_list		*cmd;

	if (argc > 1)
	{
		ft_printf("no arguments required, just: %s\n", argv[0]);
		return (1);
	}
	si_init_sighandling();
	envp_ptr = (char ***)malloc(sizeof(char **));
	*envp_ptr = array_cpy(envp);
	while (1)
	{
		cmd = NULL;
		input = pt_display();
		if (!input)
			ms_exit_ctrld(envp_ptr);
		if (!input[0])
			input = ms_input_desctruct(input);
		ms_check_input(input, envp_ptr, cmd);
	}
	return (0);
}
