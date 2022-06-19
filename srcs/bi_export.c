/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:44:48 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:44:56 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * @brief adds new variables to envp (if argc > 1) or prints envp sorted 
 * 
 * @param envp array that includes all environment variables
 * @param argc number of arguments
 * @param argv array of input arguments
 * @return char** 
 */
char	**bi_export(char **envp, int argc, char **argv)
{
	char	**envp_new;
	int		size;

	if (argc == 1)
		bi_print_sorted_env(envp);
	if (argc < 2)
		return (envp);
	envp = bi_trim_args(argc, argv, envp);
	size = sizeof_array(envp) + bi_check_spec_char_arr(argc, argv);
	envp_new = (char **)malloc((size) * sizeof(char *));
	if (!envp_new)
		error_handler(e_malloc);
	envp_new = bi_fill_envp(envp_new, envp, argc, argv);
	ms_free_array(envp);
	return (envp_new);
}

/**
 * @brief gets the length of the variable until it reaches '='
 * 
 * @param str string
 * @return int length
 */
int	bi_varlen(char *str)
{
	int		var_len;

	var_len = 0;
	while (str[var_len] != '\0')
	{
		if (str[var_len] == '=')
			return (var_len);
		var_len++;
	}
	return (var_len);
}

/**
 * @brief unsets argv if they are already in envp
 * 
 * @param argc number of arguments
 * @param argv array of arguments
 * @param envp array of environmental variables
 * @return char** 
 */
char	**bi_trim_args(int argc, char **argv, char **envp)
{
	int		i;
	char	**envp_new;
	char	**tmp;

	i = 0;
	tmp = (char **)malloc((argc + 1) * sizeof(char *));
	while (i < argc)
	{
		tmp[i] = ft_substr(argv[i], 0, bi_varlen(argv[i]));
		i++;
	}
	tmp[i] = NULL;
	envp_new = bi_unset(argc, tmp, envp);
	ms_free_array(tmp);
	return (envp_new);
}

/**
 * @brief checks if the argument at position j is the 
 * same as one of the following arguments
 * 
 * @param j position of argument
 * @param argv array of arguments
 * @return int, 1 if there is a double, 0 if not
 */
int	bi_check_dbl(int j, char *argv[])
{
	int	i;
	int	n;

	n = bi_varlen(argv[j]);
	i = j + 1;
	while (argv[i])
	{
		if (!ft_strncmp(argv[i], argv[j], n) && n == bi_varlen(argv[i]))
		{
			return (1);
		}
		i++;
	}
	return (0);
}

/**
 * @brief copies envp in envp_new and adds argv
 * 
 * @param envp_new return array of envp + argv
 * @param envp array of environmental variables
 * @param argc number of arguments in argv
 * @param argv array of arguments
 * @return char** 
 */
char	**bi_fill_envp(char **envp_new, char **envp, int argc, char **argv)
{
	int	i;
	int	j;
	int	size;

	i = -1;
	j = 1;
	size = sizeof_array(envp) + bi_check_spec_char_arr(argc, argv);
	while (++i < size - argc)
		envp_new[i] = ft_substr(envp[i], 0, ft_strlen(envp[i]));
	while (j < argc)
	{
		if (!bi_check_spec_char_argv(argv[j]))
		{
			if (!bi_check_dbl(j, argv))
				envp_new[i] = ft_substr(argv[j], 0, ft_strlen(argv[j]));
			i++;
		}
		else
			error_handler(e_args);
		j++;
	}
	envp_new[i] = NULL;
	return (envp_new);
}
