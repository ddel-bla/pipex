# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddel-bla <ddel-bla@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 17:23:53 by ddel-bla          #+#    #+#              #
#    Updated: 2024/03/22 02:54:02 by ddel-bla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COLOR DEFINITION #
GREEN = \033[0;92m
YELLOW = \033[0;93m
RESET   := \033[0m

SRC		=	is/ft_isalnum.c is/ft_isalpha.c is/ft_isascii.c is/ft_isdigit.c \
			is/ft_isprint.c mem/ft_bzero.c mem/ft_calloc.c mem/ft_memchr.c \
			mem/ft_memcmp.c mem/ft_memcpy.c mem/ft_memmove.c mem/ft_memset.c \
			put/ft_putchar_fd.c put/ft_putendl_fd.c	put/ft_putnbr_fd.c \
			put/ft_putstr_fd.c str/ft_split.c str/ft_strchr.c \
			str/ft_strcmp.c str/ft_strdup.c str/ft_striteri.c \
			str/ft_strjoin.c str/ft_strlcat.c str/ft_strlcpy.c \
			str/ft_strlen.c str/ft_strmapi.c str/ft_strncmp.c \
			str/ft_strnstr.c str/ft_strrchr.c str/ft_strtrim.c \
			str/ft_substr.c to/ft_atoi.c to/ft_atoi_ps.c to/ft_itoa.c \
			str/ft_strlenchr.c \
			to/ft_tolower.c to/ft_toupper.c \
			lst/ft_lstadd_back.c lst/ft_lstadd_front.c lst/ft_lstclear.c \
			lst/ft_lstdelone.c lst/ft_lstiter.c lst/ft_lstlast.c \
			lst/ft_lstmap.c lst/ft_lstnew.c lst/ft_lstsize.c \
			gnl/get_next_line.c gnl/get_next_line_utils.c \
			printf/ft_printf.c printf/ft_printf_utils.c 
		
OBJ		=	$(SRC:.c=.o)
NAME	=	libft.a

LIB		=	ar rcs
CC		= 	gcc

CFLAGS	=	-I ./inc -Wall -Wextra -Werror

RM		=	rm -f

.c.o:
		$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

		
$(NAME):	$(OBJ)
			$(LIB) $(NAME) $(OBJ)
			@echo "$(GREEN)libft - Compiled!$(RESET)"

all:		$(NAME)

clean:		
			$(RM) $(OBJ)
			@echo "$(GREEN)libft - Object files cleaned!$(RESET)"

fclean:		clean
			$(RM) $(NAME)
			@echo "$(GREEN)libft - Executable files cleaned!$(RESET)"

re:			fclean all bonus
			@echo "$(GREEN)libft - Re compiled!$(RESET)"

.PHONY: all clean fclean re