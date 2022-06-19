/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Loui :) <loflavel@students.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:48:02 by Loui :)           #+#    #+#             */
/*   Updated: 2022/06/12 17:48:13 by Loui :)          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

char	**bi_cd(int argc, char **argv, char **envp)
{
	char	**tmp;
	char	pwd[PATH_SIZE];

	if (argc == 1)
		chdir(ft_getenv("HOME", envp));
	else if (argc > 2)
	{
		error_handler(e_args);
		return (envp);
	}
	else if (chdir(argv[1]) != 0)
		error_handler(e_file);
	tmp = (char **)malloc(sizeof(char *) * 4);
	tmp[0] = ft_strdup("export");
	tmp[1] = ft_strjoin("OLDPWD=", ft_getenv("PWD", envp));
	tmp[2] = ft_strjoin("PWD=", getcwd(pwd, PATH_SIZE));
	tmp[3] = 0;
	envp = bi_export(envp, 3, tmp);
	ms_free_array(tmp);
	return (envp);
}
