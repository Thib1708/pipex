# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tgiraudo <tgiraudo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/24 11:12:25 by tgiraudo          #+#    #+#              #
#    Updated: 2023/03/01 11:59:35 by tgiraudo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PRINT = @printf
NAME		= pipex

FLAGS		= -Wall -Wextra -Werror

MAKEFLAGS	+= --no-print-directory

CC 			= gcc

HEADER_PATH	= include/

DIR_OBJS = .objs/

DIR_SRCS_MANDATORY = srcs/mandatory/

DIR_SRCS_BONUS = srcs/bonus/

INCLUDES 	= -I ${HEADER_PATH}

LIBFT 		= -L ./libft -lft 

LIST_SRCS_MANDATORY		=	main.c				\
							ft_pipe.c			\
							init_struct.c		\
							ft_split_cmd.c		\

OBJS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS_MANDATORY))

SRCS_MANDATORY = ${addprefix ${DIR_SRCS_MANDATORY}, ${LIST_SRCS_MANDATORY}}

LIST_SRCS_BONUS		=	main_bonus.c				\
						ft_init_struct_bonus.c		\
						ft_pipe_bonus.c 			\
						ft_split_cmd_bonus.c		\

OBJS_BONUS = $(patsubst %.c, $(DIR_OBJS)%.o, $(SRCS_BONUS))

SRCS_BONUS = ${addprefix ${DIR_SRCS_BONUS}, ${LIST_SRCS_BONUS}}

all			: ${NAME}

${DIR_OBJS}%.o 		: %.c 
				@mkdir -p $(shell dirname $@)
				@printf "${YELLOW}\033[2KCreating ${NAME}'s objects : $@\r"
				@${CC} ${FLAGS} ${INCLUDES} -c $< -o $@ 
				@printf "${GREEN}\033[2KCreating ${NAME}'s objects : DONE\r"

# ${NAME}		: ascii lib ${OBJS}
# 				@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\r"
# 				@${PRINT} "\n${YELLOW}Compiling ${NAME}..."
# 				@${CC} -fsanitize=address ${OBJS} ${LIBFT} -o ${NAME}
# 				@${PRINT} "\r${GREEN}Compiling ${NAME} : DONE${DEFAULT}\n\n"

${NAME}		: ascii lib ${OBJS_BONUS}
				@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\r"
				@${PRINT} "\n${YELLOW}Compiling ${NAME}..."
				@${CC}${OBJS_BONUS} ${LIBFT} -o ${NAME}
				@${PRINT} "\r${GREEN}Compiling ${NAME} : DONE${DEFAULT}\n\n"
				
bonus		: ascii_bonus lib ${OBJS_BONUS}
				@${PRINT} "${GREEN}${SUPPR}Creating ${NAME}'s objects : DONE\r"
				@${PRINT} "\n${YELLOW}Compiling ${NAME}..."
				@${CC} -fsanitize=address ${OBJS_BONUS} ${LIBFT} -o ${NAME}
				@${PRINT} "\r${GREEN}Compiling ${NAME} : DONE${DEFAULT}\n\n"

ascii :
		@${PRINT} "$$ASCII"	

ascii_bonus :
		@${PRINT} "$$ASCII_BONUS"	

lib :
		@make -C ./libft

clean		:
				@${PRINT} "${RED}Deleting objects : DONE\n"
				@rm -rf ${DIR_OBJS}

fclean		: clean
				@${PRINT} "${RED}Cleaning libft : DONE\n"
				@${MAKE} fclean -C ./libft
				@${PRINT} "${RED}Deleting executable : DONE\n\n${DEFAULT}"
				@rm -f ${NAME}

re			: ascii fclean all

${DIR_OBJS} :
				mkdir -p ${DIR_OBJS}
				
define ASCII

██████╗ ██╗██████╗ ███████╗██╗  ██╗
██╔══██╗██║██╔══██╗██╔════╝╚██╗██╔╝
██████╔╝██║██████╔╝█████╗   ╚███╔╝ 
██╔═══╝ ██║██╔═══╝ ██╔══╝   ██╔██╗ 
██║     ██║██║     ███████╗██╔╝ ██╗
╚═╝     ╚═╝╚═╝     ╚══════╝╚═╝  ╚═╝


endef
export ASCII

define ASCII_BONUS

██████╗  ██████╗ ███╗   ██╗██╗   ██╗███████╗
██╔══██╗██╔═══██╗████╗  ██║██║   ██║██╔════╝
██████╔╝██║   ██║██╔██╗ ██║██║   ██║███████╗
██╔══██╗██║   ██║██║╚██╗██║██║   ██║╚════██║
██████╔╝╚██████╔╝██║ ╚████║╚██████╔╝███████║
╚═════╝  ╚═════╝ ╚═╝  ╚═══╝ ╚═════╝ ╚══════╝


endef
export ASCII_BONUS

.PHONY		: all clean fclean re lib ascii

RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
SUPPR   = \r\033[2K
DEFAULT = \033[0m
