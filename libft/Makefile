# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 12:53:06 by tgiraudo          #+#    #+#              #
#    Updated: 2023/02/21 17:38:28 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= libft.a

FLAGS = -Wall -Wextra -Werror

DIR_OBJS = .objs/

OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS))

INCLUDES		= -I ${HEADERS_PATH}

HEADERS_PATH = headers/

HEADERS =	${HEADERS_PATH}ft_printf.h \
			${HEADERS_PATH}ft_printf_fd.h \
			${HEADERS_PATH}get_next_line.h \
			${HEADERS_PATH}get_next_line_bonus.h \
			${HEADERS_PATH}libft.h

SRCS	=	libft/strings/ft_strlen.c				\
			libft/char/ft_isalpha.c				\
			libft/char/ft_isalnum.c				\
			libft/char/ft_isprint.c 				\
			libft/char/ft_isascii.c 				\
			libft/char/ft_isdigit.c 				\
			libft/mem/ft_memcpy.c 				\
			libft/mem/ft_memmove.c				\
			libft/char/ft_bzero.c				\
			libft/mem/ft_memset.c				\
			libft/strings/ft_strlcpy.c				\
			libft/strings/ft_strlcat.c				\
			libft/char/ft_toupper.c				\
			libft/char/ft_tolower.c				\
			libft/strings/ft_strncmp.c				\
			libft/strings/ft_strchr.c				\
			libft/strings/ft_strrchr.c				\
			libft/mem/ft_memchr.c				\
			libft/strings/ft_atoi.c					\
			libft/mem/ft_memcmp.c				\
			libft/strings/ft_strnstr.c				\
			libft/strings/ft_split.c				\
			libft/char/ft_calloc.c				\
			libft/strings/ft_strdup.c				\
			libft/strings/ft_substr.c				\
			libft/strings/ft_strjoin.c				\
			libft/strings/ft_join_mlt.c				\
			libft/strings/ft_strtrim.c				\
			libft/strings/ft_itoa.c					\
			libft/strings/ft_strmapi.c				\
			libft/strings/ft_striteri.c				\
			libft/write/ft_putchar_fd.c			\
			libft/write/ft_putstr_fd.c			\
			libft/write/ft_putendl_fd.c			\
			libft/write/ft_putnbr_fd.c			\
			libft/lst/ft_lstnew_bonus.c			\
			libft/lst/ft_lstadd_front_bonus.c	\
			libft/lst/ft_lstsize_bonus.c		\
			libft/lst/ft_lstlast_bonus.c		\
			libft/lst/ft_lstdelone_bonus.c		\
			libft/lst/ft_lstadd_back_bonus.c	\
			libft/lst/ft_lstclear_bonus.c		\
			libft/lst/ft_lstiter_bonus.c		\
			libft/lst/ft_lstmap_bonus.c			\
\
			get_next_line/get_next_line.c				\
			get_next_line/get_next_line_utils.c			\
\
			printf/ft_printf_utils_2.c	\
			printf/ft_printf_utils.c	\
			printf/ft_printf.c			\
\
			printf_fd/ft_printf_fd_utils_2.c	\
			printf_fd/ft_printf_fd_utils.c		\
			printf_fd/ft_printf_fd.c			\


${DIR_OBJS}%.o	:	%.c ${HEADERS} Makefile
			@mkdir -p $(shell dirname $@)
			@printf "${YELLOW}\033[2KCreating libft's objects : $@\r"
			@cc ${FLAGS} ${INCLUDES} -I ./headers -c $< -o $@

${NAME}			:	${OBJS}
			@printf "${GREEN}\033[2KCreating libft's objects : DONE\r"
			@printf "\n${YELLOW}Compiling libft..."
			@ar rc ${NAME} ${OBJS}
			@echo "\r${GREEN}Compiling libft : DONE${DEFAULT}"

all	:	${NAME}

clean:
			@rm -rf ${DIR_OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY: all clean fclean re

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m