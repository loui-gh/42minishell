/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bi_heredoc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 07:59:18 by anruland          #+#    #+#             */
/*   Updated: 2022/06/12 10:16:09 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incl/minishell.h"

int	bi_heredoc(char *end, int fd, char *prompt)
{
	char	*input;
	int		len;
	char	*filename;

	filename = ft_strjoin(end, ".heredoc");
	len = ft_strlen(end) + 1;
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 0664);
	input = readline(prompt);
	while (ft_strncmp(input, end, len))
	{
		ft_putstr_fd(input, fd);
		ft_putchar_fd('\n', fd);
		ms_single_desctruct(input);
		input = readline(prompt);
		if (!input)
		{
			error_handler(e_heredoc);
			break ;
		}
	}
	close (fd);
	fd = open(filename, O_RDONLY);
	ms_single_desctruct(input);
	ms_single_desctruct(filename);
	return (fd);
}
