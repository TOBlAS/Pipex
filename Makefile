# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/02 10:37:58 by tobiaslst         #+#    #+#              #
#    Updated: 2022/12/12 15:27:25 by tcaborde         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#SETUP
NAME		=	pipex
CC			=	gcc
FLAGS		=	-Wall -Wextra -Werror
RM			=	rm -rf

#FILES AND PATH
HEADER_SRCS	=	pipex.h
HEADER_DIR	=	includes/
HEADER		=	$(addprefix $(HEADER_DIR), $(HEADER_SRCS))

PATH_SRCS	=	pipex.c utils.c fork.c error-msg.c
PATH_DIR	=	srcs/
PATH		=	$(addprefix $(PATH_DIR), $(PATH_SRCS))
OBJ_M		=	$(PATH:.c=.o)

FUNC_SRCS	=	ft_strncmp.c ft_strdup.c ft_split.c ft_strjoin.c ft_strlen.c
FUNC_DIR	=	libft/
FUNC 		=	$(addprefix $(FUNC_DIR), $(FUNC_SRCS))
OBJ_F		=	$(FUNC:.c=.o)

#COMMANDS
%.o: %.c $(HEADER) Makefile
					@${CC} ${FLAGS} -c $< -o $@
					@printf "$(ERASE)$(BLUE)[BUILDING]$(END) $@"

$(NAME):		$(OBJ_F) $(OBJ_M)
				@$(CC) $(OBJ_F) $(OBJ_M) -o $(NAME)
				@echo "$(ERASE)$(GREEN)$(NAME) created!$(DEFAULT)"

all:			$(NAME)

clean:
				@$(RM) $(OBJ_M)
				@$(RM) $(OBJ_F)
				@echo "$(YELLOW)Object files deleted!$(DEFAULT)"

fclean:			clean
				@$(RM) $(NAME)
				@echo "$(RED)Deleting EVERYTHING! ⌐(ಠ۾ಠ)¬$(DEFAULT)"

re:				fclean all

.PHONY:		all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
END=\033[0m
BLUE=\033[34m
ERASE=\033[2K\r

