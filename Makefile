# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/03 07:50:49 by ddel-bla          #+#    #+#              #
#    Updated: 2024/02/27 14:07:56 by ddel-bla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR DEFINITION #
GREEN	= \033[0;92m
YELLOW	= \033[0;93m
BLUE	= \033[0;34m
RESET	= \033[0m

SRCS	= src/pipex.c src/ft_puterror.c src/ft_out_process.c \
		src/ft_in_process.c src/ft_find_path.c src/ft_exec_proc.c 
BSRCS	= src_bonus/ft_find_path_bonus.c src_bonus/ft_in_process_bonus.c \
		src_bonus/ft_here_doc.c src_bonus/ft_mid_process_bonus.c \
		src_bonus/ft_out_process_bonus.c src_bonus/ft_puterror_bonus.c \
		src_bonus/pipex_bonus.c src/ft_exec_proc.c 
NAME	= pipex
CC		= gcc
DEBUG	= -fsanitize=address
CFLAGS	= -Wall -Werror -Wextra -I ./inc/ -I ./libft/inc/
RM		= rm -f
OBJS	= $(SRCS:.c=.o)
BOBJS	= $(BSRCS:.c=.o)
INCLUDE	= -L libft -lft
CACHE	= .cache

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE) 
	@echo "$(BLUE)pipex - Compiled!$(RESET)"

$(CACHE): $(BOBJS)
	touch $(CACHE)
	make -C libft
	$(CC) $(CFLAGS) $(BOBJS) -o $(NAME) $(INCLUDE)
	@echo "$(BLUE)pipex bonus - Compiled!$(RESET)"
	
all: $(NAME)

debug: CFLAGS += $(DEBUG)
debug: all

bonus:  $(CACHE)

bdebug: CFLAGS += $(DEBUG)
bdebug: bonus

clean:
	make -C libft clean
	$(RM) $(OBJS) $(BOBJS)
	@echo "$(BLUE)pipex - Object files cleaned!$(RESET)"

fclean:
	make -C libft fclean
	$(RM) $(OBJS) $(BOBJS) $(CACHE)
	@echo "$(BLUE)pipex - Object files cleaned!$(RESET)"
	$(RM) $(NAME)
	@echo "$(BLUE)pipex - Executable files cleaned!$(RESET)"

re: fclean all

.PHONY: all re clean fclean bonus