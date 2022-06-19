/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   si_signaling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/17 06:43:39 by anruland          #+#    #+#             */
/*   Updated: 2022/06/10 15:29:46 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

/**
 * Initializes the signal handling for the parent.
 * As soon as the signal SIGINT (Ctrl + C)
 * or SIGQUIT (Ctrl + \) arrive the specified 
 * handler takes over
 */
void	si_init_sighandling(void)
{
	sigset_t			signals;
	struct sigaction	s_action;

	sigemptyset(&signals);
	sigaddset(&signals, SIGQUIT);
	sigaddset(&signals, SIGINT);
	s_action.sa_mask = signals;
	s_action.sa_flags = SA_RESTART;
	s_action.sa_handler = &si_handler_shell;
	sigaction(SIGINT, &s_action, NULL);
	signal(SIGQUIT, SIG_IGN);
}

/**
 * Initializes the signal handling for the child.
 * As soon as the signal SIGINT (Ctrl + C)
 * or SIGQUIT (Ctrl + \) arrive the specified 
 * handler takes over
 */
void	si_init_sighandling_child(void)
{
	sigset_t			signals;
	struct sigaction	s_action;

	sigemptyset(&signals);
	sigaddset(&signals, SIGQUIT);
	sigaddset(&signals, SIGINT);
	s_action.sa_mask = signals;
	s_action.sa_flags = SA_RESTART;
	s_action.sa_handler = &si_handler_child;
	sigaction(SIGINT, &s_action, NULL);
	sigaction(SIGQUIT, &s_action, NULL);
}

/**
 * Signal handler for SIGINT and SIGQUIT for parent
 * for SIGQUIT it does nothing
 * for SIGINT the handler shows a new prompt
 * @param sig [int] the respective number of the signal
 */
void	si_handler_shell(int sig)
{
	if (sig == SIGINT)
	{
		g_errno = 130;
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
	}
}

/**
 * Signal handler for SIGINT and SIGQUIT for child
 * for SIGQUIT it does nothing
 * for SIGINT the handler shows a new prompt
 * @param sig [int] the respective number of the signal
 */
void	si_handler_child(int sig)
{
	if (sig == SIGINT)
	{
		g_errno = 130;
		ft_putchar_fd('\n', 1);
	}
	else if (sig == SIGQUIT)
	{
		g_errno = 131;
		ft_putstr_fd("Quit\n", 1);
	}
}
