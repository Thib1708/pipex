# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:53:06 by tgiraudo          #+#    #+#              #
#    Updated: 2022/12/05 17:02:15 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS	=	libft/ft_strlen.c \
			libft/ft_isalpha.c \
			libft/ft_isalnum.c \
			libft/ft_isprint.c \
			libft/ft_isascii.c \
			libft/ft_isdigit.c \
			libft/ft_memcpy.c \
			libft/ft_memmove.c \
			libft/ft_bzero.c \
			libft/ft_memset.c \
			libft/ft_strlcpy.c \
			libft/ft_strlcat.c \
			libft/ft_toupper.c \
			libft/ft_tolower.c \
			libft/ft_strncmp.c \
			libft/ft_strchr.c \
			libft/ft_strrchr.c \
			libft/ft_memchr.c \
			libft/ft_atoi.c \
			libft/ft_memcmp.c \
			libft/ft_strnstr.c \
			libft/ft_split.c \
			libft/ft_calloc.c \
			libft/ft_strdup.c \
			libft/ft_substr.c \
			libft/ft_strjoin.c \
			libft/ft_strtrim.c \
			libft/ft_itoa.c \
			libft/ft_strmapi.c \
			libft/ft_striteri.c \
			libft/ft_putchar_fd.c \
			libft/ft_putstr_fd.c \
			libft/ft_putendl_fd.c \
			libft/ft_putnbr_fd.c \
			libft/ft_lstnew_bonus.c \
			libft/ft_lstadd_front_bonus.c \
			libft/ft_lstsize_bonus.c \
			libft/ft_lstlast_bonus.c \
			libft/ft_lstdelone_bonus.c \
			libft/ft_lstadd_back_bonus.c \
			libft/ft_lstclear_bonus.c \
			libft/ft_lstiter_bonus.c \
			libft/ft_lstmap_bonus.c \
\
			get_next_line/get_next_line.c				\
			get_next_line/get_next_line_utils.c			\
			get_next_line/get_next_line_bonus.c			\
			get_next_line/get_next_line_utils_bonus.c	\
\
			printf/ft_printf_utils_2.c	\
			printf/ft_printf_utils.c	\
			printf/ft_printf.c

NAME		= libft.a

OBJS		= ${SRCS:.c=.o}

INCLUDES		= -I ${HEADERS_PATH}

HEADERS_PATH = headers/

HEADERS =	${HEADERS_PATH}ft_printf.h \
			${HEADERS_PATH}get_next_line.h \
			${HEADERS_PATH}get_next_line_bonus.h \
			${HEADERS_PATH}libft.h

FLAGS = -Wall -Wextra -Werror

%.o : %.c ${HEADERS} Makefile
	@cc ${FLAGS} ${INCLUDES} -c $< -o $@

${NAME}:	${OBJS}
			@ar rc ${NAME} ${OBJS}

all:		${NAME}

clean:
			@rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re