# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: anruland <anruland@students.42wolfsburg    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/07 09:37:00 by anruland         #+#    #+#              #
#    Updated: 2022/03/22 10:13:07 by anruland         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Config
NAME 		= libft.a
CC			= gcc
CFLAGS		= -Werror -Wall -Wextra
AR			= ar rcs

# Files
SRC_C 		= ft_atoi.c ft_memchr.c ft_split.c ft_strmapi.c\
				ft_bzero.c ft_lstadd_front.c ft_memcmp.c ft_strchr.c ft_strncmp.c\
				ft_calloc.c ft_memcpy.c ft_strcpy.c ft_strnstr.c\
				ft_isalnum.c ft_memmove.c ft_strdup.c ft_strrchr.c\
				ft_isalpha.c ft_memset.c ft_striteri.c ft_strtrim.c\
				ft_isascii.c ft_putchar_fd.c ft_strjoin.c ft_substr.c\
				ft_isdigit.c ft_putendl_fd.c ft_strlcat.c ft_tolower.c\
				ft_isprint.c ft_putnbr_fd.c ft_strlcpy.c ft_toupper.c\
				ft_itoa.c ft_putstr_fd.c ft_strlen.c \
				ft_putnbr_ulong_fd_base.c ft_hexlen.c ft_nbrlen_base_sign.c \
				ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c\
				ft_lstmap.c ft_lstnew.c ft_lstsize.c ft_lstadd_back.c\
				ft_printf.c ft_printf_utils.c\
				get_next_line.c \
				ft_linecount.c ft_printerror.c ft_realloc.c\
				ft_strlen_c.c ft_strndup.c ft_atol.c
SRC_O 		= $(SRC_C:%.c=%.o)

# Rules
all: $(NAME)

$(NAME): $(SRC_O)
	@$(AR) $(NAME) $(SRC_O)

%.o: %.c
	$(CC) -c $(CFLAGS) -o $@ $^

clean:
	@/bin/rm -f $(SRC_O)

fclean: clean
	@/bin/rm -f $(NAME)

re: fclean all
