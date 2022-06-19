/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:45:00 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:45:09 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	checker(char *s)
{
	size_t	i;

	i = 1;
	if (!(ft_strncmp("-n", s, 2)))
	{
		while (i < ft_strlen(s))
		{
			if (s[i] != 'n')
				return (0);
			i++;
		}
		return (1);
	}
	return (0);
}

/**
* Going through the arguments and handling the -n option flag
* Test cases: echo -> output: a newline
* echo -n -> output: nothing, as the newlined was surpressed by the flag
* echo la la -> output: la la (keeping the spaces and adding a newline)
* echo -n -nn -nnk -> output: -nnk
* echo -nk -n -> output: -nk -n
* The checker's use: to verify if the flag -n is found. If a char != n is found
* the return value is 0 & in the second while loop of echo_builtin we print
* @params: will be updated if needed, based on the rest of the code
**/

void	bi_echo(int argc, char **argv)
{
	size_t	i;
	int		nl_flag;

	nl_flag = 1;
	if (argc == 1)
		ft_printf("\n");
	else
	{
		i = 1;
		while (argv[i] && checker(argv[i]))
		{
			i++;
			nl_flag = 0;
		}
		while (argv[i])
		{
			ft_printf("%s", argv[i]);
			if (argv[i + 1])
				ft_printf(" ");
			i++;
		}
		if (nl_flag)
			ft_printf("\n");
	}
}
