/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:46:25 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:46:41 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * @brief unsets argv from envp
 * 
 * @param argc number of arguments
 * @param argv array of arguments that will be unset
 * @param envp array of environmental variables from which argv will be unset
 * @return char** envp without argv
 */
char	**bi_unset(int argc, char **argv, char **envp)
{
	int		i;
	char	**envp_new;
	int		n;

	check_spec_char_arr_unset(argv);
	i = 1;
	n = 0;
	while (i < argc)
	{
		if (!bi_check_dbl(i, argv))
			n = n + bi_is_env(envp, argv[i]);
		i++;
	}
	if (n == 0)
		return (envp);
	envp_new = (char **)malloc((sizeof_array(envp) - n + 1) * sizeof(char *));
	bi_fill_array(envp, argv, envp_new);
	ms_free_array(envp);
	return (envp_new);
}

/**
 * @brief returns the size of an array
 * 
 * @param arr array 
 * @return int size of arr
 */
int	sizeof_array(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		i++;
	return (i);
}
