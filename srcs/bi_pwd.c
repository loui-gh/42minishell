/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:45:57 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:46:05 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * pwd (Print Working Directory) -> it prints the path of the working directory
 * char *getcwd(char *buf, size_t size)
 * getcwd() places an absolute pathname of the current working directory
 * in the array pointed to by buf, and returns buf. 
 * The size = size in bytes of the character array pointed to by the buf arg. 
 * If buf is a null pointer, the behaviour of getcwd() is undefined.
 * The return value represents our current working directory.
 * size 1024 is MAX_PATH on macOS and 4096 on linux
 * @params: none
 **/

int	bi_pwd(void)
{
	char	pwd[PATH_SIZE];

	if (getcwd(pwd, PATH_SIZE) == NULL)
		return (EXIT_FAILURE);
	ft_printf("%s\n", pwd);
	return (EXIT_SUCCESS);
}
