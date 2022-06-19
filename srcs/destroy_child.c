/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_child.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 19:29:43 by anruland          #+#    #+#             */
/*   Updated: 2022/06/08 13:28:32 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

void	destroy_child(t_list *cmd, pid_t *cradle, int **fd)
{
	ms_destroy_pipes(fd, ft_lstsize(cmd));
	ms_free_array(cmd->envp);
	free(cmd->envp_triple);
	ms_destructor(cmd);
	free(cradle);
	exit (0);
}
