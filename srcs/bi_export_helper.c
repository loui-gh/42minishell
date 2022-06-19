/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_export_helper.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/04 17:45:46 by loflavel          #+#    #+#             */
/*   Updated: 2022/06/10 15:30:31 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * @brief finds the next alphabetical string in envp that comes after tmp
 * 
 * @param tmp last printed string
 * @param envp array of environmental variables
 * @return char* next string that will be printed
 */
char	*bi_get_next(char *tmp, char **envp, int i)
{
	int		diff;
	char	*next;
	int		min;

	min = INT_MIN;
	next = tmp;
	while (envp[i])
	{
		diff = ft_strncmp(tmp, envp[i], 1);
		if (diff < 0 && diff > min)
			bi_exp_ass_val(&next, &min, envp[i], diff);
		else if (diff < 0 && diff == min)
		{
			if (ft_strncmp(next, envp[i], ft_strlen(next) + 1) > 0)
				bi_exp_ass_val(&next, &min, envp[i], diff);
		}
		else if (diff == 0 && ft_strncmp(tmp, envp[i], ft_strlen(next) + 1) < 0)
		{
			if (next == tmp || ft_strncmp(next, envp[i], ft_strlen(next)) > 0)
				bi_exp_ass_val(&next, &min, envp[i], 0);
		}
		i++;
	}
	return (next);
}
// char	*bi_get_next(char *tmp, char **envp)
// {
// 	int		i;
// 	int		diff;
// 	char	*next;
// 	int		min;

// 	i = 0;
// 	min = INT_MIN;
// 	next = tmp;
// 	while (envp[i])
// 	{
// 		diff = ft_strncmp(tmp, envp[i], 1);
// 		if (diff < 0 && diff > min)
// 		{
// 			next = envp[i];
// 			min = diff;
// 		}
// 		else if (diff < 0 && diff == min)
// 		{
// 			if (ft_strncmp(next, envp[i], ft_strlen(next) + 1) > 0)
// 			{	
// 			next = envp[i];
// 			min = diff;
// 			}
// 		}
// 		else if (diff == 0 && ft_strncmp(tmp, envp[i], ft_strlen(next) + 1) < 0)
// 		{
// 			if (next == tmp || ft_strncmp(next, envp[i], ft_strlen(next)) > 0)
// 			{	
// 			next = envp[i];
// 			min = 0;
// 			}
// 		}
// 		i++;
// 	}
// 	return (next);
// }

/**
 * @brief prints tmp in the way that is needed in export:
 * adds 'declare -x ' at the start and adds quotes around string after '=' 
 * 
 * @param tmp string that should be printed
 */
void	bi_print_export(char *tmp)
{
	int	i;

	i = 0;
	ft_printf("declare -x ");
	while (tmp[i] && tmp[i] != '=')
	{
		ft_printf("%c", tmp[i]);
		i++;
	}
	if (tmp[i] == '=')
	{
		ft_printf("=");
		ft_putchar_fd('"', 1);
		i++;
		ft_printf("%s", &tmp[i]);
		ft_putchar_fd('"', 1);
	}
	ft_printf("\n");
}

/**
 * @brief prints the array envp alphabetically sorted
 * 
 * @param envp array of environmental variables
 */
void	bi_print_sorted_env(char **envp)
{
	int		i;
	char	*tmp;
	int		size;

	i = 0;
	tmp = envp[0];
	size = sizeof_array(envp);
	while (envp[i])
	{
		if (ft_strncmp(tmp, envp[i], ft_strlen(envp[i])) > 0)
			tmp = envp[i];
		i++;
	}
	bi_print_export(tmp);
	while (size - 1 > 0)
	{
		tmp = bi_get_next(tmp, envp, 0);
		bi_print_export(tmp);
		size--;
	}
}

/**
 * @brief checks if there are special characters in the string before the '='
 * 
 * @param str string
 * @return int, 1 if special character is found, 0 if not
 */
int	bi_check_spec_char_argv(char *str)
{
	int	j;

	j = 0;
	if (ft_strlen (str) < 1)
		return (1);
	while (str[j] != '\0' && str[j] != '=' )
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
 * @brief counts how many strings in the array have special 
 * characters before the '='
 * 
 * @param argc number of arguments
 * @param argv array of arguments
 * @return int number of strings with special arguments found
 */
int	bi_check_spec_char_arr(int argc, char *argv[])
{
	int	i;
	int	count;

	count = 0;
	i = 1;
	while (argv[i])
	{
		count += bi_check_spec_char_argv(argv[i]);
		i++;
	}
	return (argc - count);
}
