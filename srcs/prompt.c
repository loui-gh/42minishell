/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 18:02:08 by anruland          #+#    #+#             */
/*   Updated: 2022/06/07 18:58:55 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * Displays the prompt and checks the input for empty input and
 * only spaces input. it only adds the command to history if 
 * it is not empty.
 * Returns the input as char pointer that needs to be free'd
 */
char	*pt_display(void)
{
	char	*input;
	char	*prompt;
	char	*ret;

	prompt = "Shelldon$ ";
	input = readline(prompt);
	if (!input)
		return (NULL);
	if (!input_empty(input))
		add_history(input);
	if (!input[0])
		return (input);
	ret = ft_strtrim(input, " ");
	free(input);
	return (ret);
}

	// prompt = pt_get_prompt();
	// free(prompt);
// char	*pt_get_prompt(void)
// {
// 	char	*prompt;
// 	char	*tmp;
// 	char	*ret;
// 	char	pwd[1024];

// 	getcwd(pwd, 1024);
// 	prompt = "\e[1;31mShelldon: \e[1;34m";
// 	tmp = ft_strjoin(prompt, pwd);
// 	ret = "\e[0m$ ";
// 	prompt = ft_strjoin(tmp, ret);
// 	free(tmp);
// 	return (prompt);
// }
