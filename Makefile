CC			= gcc 
CFLAGS		= -Wall -Wextra -Werror
LFLAGS		= -lreadline 
RM			= rm -f
SRCD		= ./srcs/
SRC			= main.c prompt.c error.c si_signaling.c pa_quotes.c pa_parsing.c \
				pa_redirect.c pa_pipes.c pa_cmd.c destructor.c error_pipe_red.c \
				pa_builtin_or_exec.c pa_cash.c bi_echo.c ex_main.c ex_child.c \
				ex_infile_outfile.c pa_helper.c bi_cd.c bi_unset.c bi_pwd.c bi_env.c \
				bi_export.c bi_exit.c bi_export_helper.c bi_unset_helper.c bi_heredoc.c \
				pa_cash_utils.c bi_export_helper2.c destroy_child.c
# Command to add the source folder prefix (instead of having it added manually to SRC)
SRCF		= $(addprefix $(SRCD),$(SRC))
OBJD		= ./objs/
# for every SRCF file which is an .c file an o file will be created according to the implicit rule (see $(OBJD)%.o: $(SRCD)%.c)
OBJF		= $(SRCF:$(SRCD)%.c=$(OBJD)%.o)
BUILD		= $(OBJF:$(OBJD)%.o)


NAME		= minishell
HEADD		= ./incl/
HEADF		= minishell.h

LIBFTDIR	= ./libs/libft/
LIBFT_OBJD	= objs
LIBFT_SRCD	= srcs/
LIBFTL		= libft.a

LIBFT_OBJF    = ${LIBFTDIR}/*.o
#LIBFT_MAKE    = make -C ${LIBFTDIR}

#if to the respective c file in the source directory no matching o file in the object
#directory is available, then create it according to the following rules:
#Note: the object directory will only be created if not existing already. -p flag throws no errors when already there
#-p is used to prevent the creation of the object directory if it already exists
# add this to Line 41 if on a shitty Mac :)   -I/usr/local/opt/readline/include
$(OBJD)%.o: $(SRCD)%.c
	@mkdir -p $(OBJD)
	$(CC) $(CFLAGS) -I ${HEADD} -c -o $@ $< -I/usr/local/opt/readline/include

# $(NAME):	${OBJF}
# 			make libftmake
# 			$(CC) $(CFLAGS) $(SRCF) -o $(NAME) $(HEADD)$(HEADF) $(LIBFTD)$(LIBFTL)
# add this lib if you are on a Mac :) -L/usr/local/opt/readline/lib
$(NAME):	setup ${OBJF}
			$(CC) $(CFLAGS) $(SRCF) -o $(NAME) -L $(HEADD) $(LIBFTDIR)$(LIBFTL) $(LFLAGS) -L/usr/local/opt/readline/lib


all:		${NAME}

setup:
			$(MAKE) -C $(LIBFTDIR)

clean:
			${RM} ${OBJD}*.o
			make -C ${LIBFTDIR} clean

fclean:		clean
			${RM} ${NAME}
			${RM} ${LIBFTDIR}${LIBFTL}
			${RM} ${HEADD}pipex.h.gch

re:			fclean all

.PHONY:		all clean fclean re setup