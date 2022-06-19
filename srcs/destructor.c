/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destructor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 11:43:11 by anruland          #+#    #+#             */
/*   Updated: 2022/06/07 19:10:14 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * destroys one single pointer
 * @param str [void *] pointer to free
 */
void	ms_single_desctruct(void *str)
{
	if (str)
		free(str);
	str = NULL;
}

/**
 * frees a pointer to pointer
 * @param argv [char **] pointer to pointer to free
 */
void	ms_free_array(char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		ms_single_desctruct((void *)argv[i]);
		i++;
	}
	ms_single_desctruct((void *)argv);
}

/**
 * destroys allocated memory for the pipes
 * n - 2 -> n children - 1 pipes - 1 index
 * @param ptr [int **] pointer to the pipes
 * @param n [int] number of commands
 */
void	ms_destroy_pipes(int **ptr, int n)
{
	int	i;

	i = n - 2;
	while (i >= 0)
	{
		if (ptr[i])
			free(ptr[i]);
		ptr[i] = NULL;
		i--;
	}
	if (ptr)
		free(ptr);
	ptr = NULL;
}

/**
 * clears the list of type t_files
 * @param lst [t_files *]
 */
void	ft_filesclear(t_files *lst)
{
	t_files	*temp;
	char	*filename;

	while (lst)
	{
		temp = lst;
		if (temp->content[1] == '<')
		{
			filename = ft_strjoin(&(temp->content[2]), ".heredoc");
			unlink(filename);
			free(filename);
		}
		lst = temp->next;
		free(temp->content);
		free(temp);
	}
	free(lst);
	lst = NULL;
}

/**
 * clears the list of type t_list without using a function pointer
 * @param lst [t_list *]
 */
//void	ft_lstclear2(t_list *lst)
//{
//	t_list	*temp;

//	while (lst)
//	{
//		temp = lst;
//		lst = temp->next;
//		free(temp);
//	}
//	lst = NULL;
//}

/**
 * destructor for the command struct
 * @param cmd [t_list *] command struct to destroy
 */
void	ms_destructor(t_list *cmd)
{
	t_list	*tmp;

	tmp = cmd;
	while (tmp)
	{
		ms_free_array(tmp->argv);
		ft_filesclear(tmp->infile);
		ft_filesclear(tmp->outfile);
		tmp = tmp->next;
	}
	ft_lstclear(&cmd, ms_single_desctruct);
}
