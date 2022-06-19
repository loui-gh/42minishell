/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_unset_helper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 18:22:15 by loflavel          #+#    #+#             */
/*   Updated: 2022/06/10 15:30:31 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * @brief checks if str is part of envp
 * 
 * @param envp array
 * @param str string
 * @return int, 1 if str is found, 0 if not 
 */
int	bi_is_env(char **envp, char *str)
{
	int	i;

	i = 0;
	while (i < sizeof_array(envp))
	{
		if (!ft_strncmp(envp[i], str, ft_strlen(str)))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief checks if str is part of envp
 * 
 * @param envp array
 * @param str string
 * @return int, 1 if str is found, 0 if not 
 */
int	bi_unset_str(char **argv, char *str)
{
	int	i;

	i = 0;
	while (i < sizeof_array(argv))
	{
		if (!ft_strncmp(argv[i], str, ft_strlen(argv[i])))
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief copies all elements of envp that are not in argv in envp_new
 * 
 * @param envp array of environmental variables
 * @param argv array of arguments that should not be in envp_new
 * @param envp_new return array
 * @return char** 
 */
void	bi_fill_array(char **envp, char **argv, char **envp_new)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (j < sizeof_array(envp))
	{
		if (!bi_unset_str(argv, envp[j]))
		{
			envp_new[i] = ft_substr(envp[j], 0, ft_strlen(envp[j]));
			i++;
		}
		j++;
	}
	envp_new[i] = NULL;
}

/**
 * @brief checks if a string includes special characters
 * 
 * @param str string
 * @return int, 1 if special characters are found, 0 if not 
 */
int	check_spec_char_unset(char *str)
{
	int	j;

	j = 0;
	while (str[j] != '\0')
	{
		if (!(ft_isalpha(str[0]) || str[0] == '_'))
			return (1);
		if (!(ft_isalpha(str[j]) || str[j] == '_' || ft_isdigit(str[j])))
			return (1);
		j++;
	}
	return (0);
}

/**
 * @brief prints error message if a string in argv has special characters
 * 
 * @param argv array of arguments
 */
void	check_spec_char_arr_unset(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (check_spec_char_unset(argv[i]))
			error_handler(e_args);
		i++;
	}
}
