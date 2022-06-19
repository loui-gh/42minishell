/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/16 15:58:51 by loflavel          #+#    #+#             */
/*   Updated: 2022/06/12 10:13:51 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <termios.h>
# include <unistd.h>
# include <sys/types.h>
# include <dirent.h>
# include <string.h>
# include <curses.h>
# include <term.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <errno.h>
# include <readline/readline.h>
# include <readline/history.h>
# include "../libs/libft/libft.h"
# include <signal.h>
# include <sys/wait.h>
# include <limits.h>

# define WRITE 1
# define READ 0
# ifdef __linux__
// Linux
#  define PATH_SIZE 4096
# else
// Mac
#  define PATH_SIZE 1024
# endif

extern int	g_errno;

enum e_fd
{
	STDIN = 0,
	STDOUT,
	STDERR,
};

enum e_errors
{
	e_success = 0,
	e_pipe = 1,
	e_redirect,
	e_quotes,
	e_malloc,
	e_unknown,
	e_child_died,
	e_file,
	e_dir,
	e_command,
	e_args,
	e_heredoc
};

/* error.c */
int		input_error(char *str);
int		error_handler(int error);
int		input_empty(char *str);

/* error_pipe_red.c - Redirects and Pipes */
int		error_check(char *str);
int		error_count_c(char *str, char c, int count);
int		error_check_redirect(t_list *cmd);
int		error_count_pipe(char *str);

/* prompt.c */
char	*pt_display(void);
char	*pt_get_prompt(void);

/* si_signaling.c */
void	si_init_sighandling(void);
void	si_handler_shell(int sig);
void	si_init_sighandling_child(void);
void	si_handler_child(int sig);

/* pa_parsing.c */
t_list	*pa_parse_input(char *input, t_list *cmd_input, char ***envp);
int		pa_skip_quotes(char *input);
void	init_cmd(t_list *cmd, char ***envp);

/* pa_quotes */
void	pa_kill_quotes(t_list *cmd);
char	*pa_really_kill_em_now(char *str, int i, char *tmp, int quotes);
void	pa_save_w_o_quotes(char **result, char *str, char *last, int i);

/* builtin_or_exec.c */
void	pa_is_builtin(t_list *cmd);
void	pa_is_exec(t_list *cmd);

/* pa_pipes.c */
int		pa_get_pipe(t_list **cmd, char *input, char ***envp);

/* pa_redirect.c */
void	pa_parse_redirect(t_list *cmd);
int		pa_get_redirect(t_list *cmd);
void	pa_save_redirect(t_list *cmd, char *redirect, int i);
void	pa_create_file_ll(t_list *cmd, char *outf, char direction);

/* pa_cmd.c */
void	pa_get_cmd(t_list *cmd, char *input, int count);
int		pa_count_cmd(t_list *cmd, char *input);
void	pa_parse_cmd(t_list *cmd);

/* pa_cash.c */
char	*pa_get_cash(char *tmp, char *result, int *i, char **envp);
char	*pa_skip_to_cash(char *tmp, char *result, int *i);
char	*pa_parse_cash(char *input, char **envp);
char	*ft_getenv(char *str, char **envp);
char	*pa_get_change(char *tmp, char *result, int i, int start);

/* pa_cash_utils.c */
char	*pa_get_cash_qmark(int *i, char *result);
int		pa_parse_cash_while(char **result, char *tmp, int *start, char **envp);

/* pa_helper.c */
int		ft_strlen_names(char *str);
char	*ft_join(char *s1, char *s2);
char	*ft_strrchr_mod(const char *s, int c, int end);
int		ft_ignore_char(char c);

/* debug.c */
void	debug_print_list(t_list *a);

/* destructor.c */
void	ms_single_desctruct(void *str);
void	ms_destructor(t_list *cmd);
void	ms_destroy_pipes(int **ptr, int n);
void	ms_free_array(char **argv);
void	ft_filesclear(t_files *lst);

/* destroy_child.c */
void	destroy_child(t_list *cmd, pid_t *cradle, int **fd);

/* utils */
char	*ft_strjoin_mod(char const *s1, char const *s2, size_t lazy, char x);

/* builtins */
void	bi_echo(int argc, char **argv);
char	**bi_cd(int argc, char **argv, char **envp);
void	bi_env(char **envp);
int		bi_pwd(void);
int		bi_exit(t_list *cmd);
int		bi_heredoc(char *end, int fd, char *prompt);

/* builtin export */
char	**bi_unset(int argc, char **argv, char **envp);
int		sizeof_array(char **arr);
void	check_spec_char_arr_unset(char **argv);
int		check_spec_char_unset(char *str);
void	bi_fill_array(char **envp, char **argv, char **envp_new);
int		bi_is_env(char **envp, char *str);

/* builtin export */
char	**bi_export(char **envp, int argc, char **argv);
char	**bi_fill_envp(char **envp_new, char **envp, int argc, char **argv);
int		bi_check_dbl(int j, char **argv);
int		bi_varlen(char *str);
char	**bi_trim_args(int argc, char **argv, char **envp);
char	*bi_get_next(char *tmp, char **envp, int i);
void	bi_print_export(char *tmp);
void	bi_print_sorted_env(char **envp);
int		bi_check_spec_char_argv(char *str);
int		bi_check_spec_char_arr(int argc, char **argv);
void	bi_exp_ass_val(char **next, int *min, char *next_value, int min_value);

/* ex_main.c */
void	ex_execute(t_list *cmd);
void	ex_give_birth(pid_t *cradle, int **fd, int n, t_list *cmd);
void	ex_open_pipes(int **fd, int n);

/* ex_child.c */
void	ex_child(t_list *cmd, int **fd, int child, pid_t *cradle);
t_list	*ex_get_cmd_child(t_list *cmd, int child);
void	ex_execute_cmd(t_list *cmd);

/* ex_infile_outfile.c */
int		ex_infile(t_list *cmd, int fd_in, int child, int **fd);
int		ex_outfile(t_list *cmd, int fd_out, int child, int **fd);

/* main.c */
char	*ms_input_desctruct(void *str);

#endif
