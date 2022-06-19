/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:51:18 by anruland         #+#    #+#             */
/*   Updated: 2022/03/22 10:13:01 by anruland         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <stdarg.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# ifndef FD_MAX
#  define FD_MAX 1024
# endif

typedef enum e_cmd_type {
	unknown = 0,
	exec,
	echo_b,
	cd,
	pwd,
	export,
	unset,
	env,
	exit_b
}	t_cmd_type;

typedef struct s_files
{
	char			*content;
	struct s_files	*next;
}					t_files;

typedef struct s_list
{
	char			*content;
	int				argc;
	char			**argv;
	t_cmd_type		type;
	struct s_files	*infile;
	struct s_files	*outfile;
	char			***envp_triple;
	char			**envp;
	struct s_list	*next;
}	t_list;

/* ************** Part 1 ************ */

void	*ft_memset(void *b, int c, size_t len);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t elem, size_t elsize);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
size_t	ft_strlen(const char *str);
char	*ft_strdup(char *src);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char	*haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, unsigned int n);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);

/* ************** Part 2 ************ */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);
char	*ft_itoa(int n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int nb, int fd);

/* ************** Bonus ************ */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_front(t_list **lst, t_list *new);
int		ft_lstsize(t_list *lst);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	ft_lstdelone(t_list *lst, void (*del)(void *));
void	ft_lstclear(t_list **lst, void (*del)(void *));
void	ft_lstiter(t_list *lst, void (*f)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

/* ************** added stuff ************ */
char	*ft_strcpy(char *dest, char *src);
void	ft_putnbr_ulong_fd_base(unsigned long nb, int fd, int base, int up);
int		ft_hexlen(unsigned long nb);
size_t	ft_nbrlen_base_sign(long long nbr, int sign, int base);
void	*ft_realloc(void *addr, size_t size);
int		ft_printerror(char *errormsg);
int		ft_linecount(char *dir);
char	*ft_strndup(char *src, int len);
int		ft_strlen_c(char *str, char c);
long	ft_atol(const char *str);
int		ft_is_whitespace(char c);

/* ************** ft_printf ************ */
int		ft_printf(const char *format, ...);
int		ft_count_args_printf(const char *format);
size_t	ft_nbrlen(long long nbr, int sign, int base);
int		ft_printf_strlen(char *str);

/* ************** get_next_line ************ */
char	*ft_gnl_join(char *main_buf, char *buf);
char	*ft_gnl_read_file(int fd, char *main_buf);
char	*ft_gnl_prepare_line(const char *main_buf);
char	*ft_gnl_prepare_next(char *main_buf, unsigned int i, unsigned int j);
char	*get_next_line(int fd);

/* ************** minishell ************ */
t_files	*ft_filelast(t_files *lst);
void	ft_fileadd_back(t_files **lst, t_files *new);
t_files	*ft_filenew(void *content);

#endif